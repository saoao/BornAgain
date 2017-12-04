// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/FitParameterItems.cpp
//! @brief     Implements FitParameterItems family of classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "FitParameterItems.h"
#include "ComboProperty.h"
#include "GUIHelpers.h"
#include "ModelPath.h"
#include "FitParameter.h"
#include "ParameterTreeItems.h"
#include "JobItem.h"
#include <cmath>

namespace
{

ComboProperty fitParameterTypeCombo()
{
    QStringList tooltips = QStringList() << QStringLiteral("Fixed at given value")
                                         << QStringLiteral("Limited in the range [min, max]")
                                         << QStringLiteral("Limited at lower bound [min, inf]")
                                         << QStringLiteral("Limited at upper bound [-inf, max]")
                                         << QStringLiteral("No limits imposed to parameter value");

    ComboProperty result;
    result << Constants::FITPAR_FIXED << Constants::FITPAR_LIMITED
           << Constants::FITPAR_LOWERLIMITED << Constants::FITPAR_UPPERLIMITED
           << Constants::FITPAR_FREE;
    result.setValue(Constants::FITPAR_LIMITED);
    result.setToolTips(tooltips);
    return result;
}

const double range_factor = 0.5;
}

// ----------------------------------------------------------------------------

const QString FitParameterLinkItem::P_LINK = "Link";
const QString FitParameterLinkItem::P_DOMAIN = "Domain";

FitParameterLinkItem::FitParameterLinkItem() : SessionItem(Constants::FitParameterLinkType)
{
    addProperty(P_LINK, "");
    addProperty(P_DOMAIN, "");
}

// ----------------------------------------------------------------------------

const QString FitParameterItem::P_TYPE = "Type";
const QString FitParameterItem::P_START_VALUE = "Value";
const QString FitParameterItem::P_MIN = "Min";
const QString FitParameterItem::P_MAX = "Max";
const QString FitParameterItem::T_LINK = "Link tag";

FitParameterItem::FitParameterItem() : SessionItem(Constants::FitParameterType)
{
    addProperty(P_TYPE, fitParameterTypeCombo().variant());
    addProperty(P_START_VALUE, 0.0);
    addProperty(P_MIN, 0.0);
    addProperty(P_MAX, 0.0)->setEnabled(false);
    registerTag(T_LINK, 0, -1, QStringList() << Constants::FitParameterLinkType);
    setDefaultTag(T_LINK);

    mapper()->setOnPropertyChange([this](const QString& name) {
        if (name == P_TYPE)
            onTypeChange();
    });

    onTypeChange();
}

//! Inits P_MIN and P_MAX taking into account current value and external limits

void FitParameterItem::initMinMaxValues(const RealLimits& limits)
{
    double value = getItemValue(P_START_VALUE).toDouble();

    double dr(0);
    if (value == 0.0) {
        dr = 1.0 * range_factor;
    } else {
        dr = std::abs(value) * range_factor;
    }

    if (isLimited()) {
        double min = value - dr;
        double max = value + dr;

        if (limits.hasLowerLimit() && min < limits.getLowerLimit())
            min = limits.getLowerLimit();

        if (limits.hasUpperLimit() && max > limits.getUpperLimit())
            max = limits.getUpperLimit();

        setItemValue(P_MIN, min);
        setItemValue(P_MAX, max);
    }
}

//! Creates domain's FitParameter.

std::unique_ptr<FitParameter> FitParameterItem::createFitParameter() const
{
    if (getItems(FitParameterItem::T_LINK).empty())
        return std::unique_ptr<FitParameter>();

    std::unique_ptr<FitParameter> result(new FitParameter);
    result->setStartValue(getItemValue(FitParameterItem::P_START_VALUE).toDouble());
    result->setLimits(attLimits());

    const JobItem* jobItem = dynamic_cast<const JobItem*>(ModelPath::ancestor(this, Constants::JobItemType));
    Q_ASSERT(jobItem);

    foreach (SessionItem* linkItem, getItems(FitParameterItem::T_LINK)) {
        QString link = linkItem->getItemValue(FitParameterLinkItem::P_LINK).toString();

        ParameterItem *parItem = dynamic_cast<ParameterItem*>(
                    ModelPath::getItemFromPath(link, jobItem->parameterContainerItem()));
        Q_ASSERT(parItem);

        QString translation = "*/" + ModelPath::itemPathTranslation(*parItem->linkedItem(), jobItem);
        parItem->setItemValue(ParameterItem::P_DOMAIN, translation);

        result->addPattern(translation.toStdString());
    }

    return result;
}

//! Constructs Limits correspodning to current GUI settings.

AttLimits FitParameterItem::attLimits() const
{
    if (isFixed()) {
        return AttLimits::fixed();
    }

    else if (isLimited()) {
        return AttLimits::limited(getItemValue(P_MIN).toDouble(), getItemValue(P_MAX).toDouble());
    }

    else if (isLowerLimited()) {
        return AttLimits::lowerLimited(getItemValue(P_MIN).toDouble());
    }

    else if (isUpperLimited()) {
        return AttLimits::upperLimited(getItemValue(P_MAX).toDouble());
    }

    else if (isFree()) {
        return AttLimits::limitless();
    }

    else {
        throw GUIHelpers::Error("FitParameterItem::attLimits() -> Error. Unknown limit type");
    }
}

QString FitParameterItem::parameterType() const
{
    ComboProperty partype = getItemValue(P_TYPE).value<ComboProperty>();
    return partype.getValue();
}

//! Enables/disables min, max properties on FitParameterItem's type

void FitParameterItem::onTypeChange()
{
    if (isFixed()) {
        setLimitEnabled(P_MIN, false);
        setLimitEnabled(P_MAX, false);
    }

    else if (isLimited()) {
        setLimitEnabled(P_MIN, true);
        setLimitEnabled(P_MAX, true);
    }

    else if (isLowerLimited()) {
        setLimitEnabled(P_MIN, true);
        setLimitEnabled(P_MAX, false);
    }

    else if (isUpperLimited()) {
        setLimitEnabled(P_MIN, false);
        setLimitEnabled(P_MAX, true);
    }

    else if (isFree()) {
        setLimitEnabled(P_MIN, false);
        setLimitEnabled(P_MAX, false);
    }
}

//! Set limit property with given name to the enabled state

void FitParameterItem::setLimitEnabled(const QString& name, bool enabled)
{
    if (isTag(name)) {
        SessionItem* propertyItem = getItem(name);
        Q_ASSERT(propertyItem);
        propertyItem->setEnabled(enabled);
        propertyItem->setEditable(enabled);
    }
}

bool FitParameterItem::isLimited() const
{
    return parameterType() == Constants::FITPAR_LIMITED;
}

bool FitParameterItem::isFree() const
{
    return parameterType() == Constants::FITPAR_FREE;
}

bool FitParameterItem::isLowerLimited() const
{
    return parameterType() == Constants::FITPAR_LOWERLIMITED;
}

bool FitParameterItem::isUpperLimited() const
{
    return parameterType() == Constants::FITPAR_UPPERLIMITED;
}

bool FitParameterItem::isFixed() const
{
    return parameterType() == Constants::FITPAR_FIXED;
}

// ----------------------------------------------------------------------------

const QString FitParameterContainerItem::T_FIT_PARAMETERS = "Data tag";

FitParameterContainerItem::FitParameterContainerItem()
    : SessionItem(Constants::FitParameterContainerType)
{
    registerTag(T_FIT_PARAMETERS, 0, -1, QStringList() << Constants::FitParameterType);
    setDefaultTag(T_FIT_PARAMETERS);
}

//! returns FitParameterItem for given link (path in model)

FitParameterItem* FitParameterContainerItem::fitParameterItem(const QString& link)
{
    foreach (SessionItem* item, getItems(T_FIT_PARAMETERS)) {
        foreach (SessionItem* linkItem, item->getItems(FitParameterItem::T_LINK)) {
            if (link == linkItem->getItemValue(FitParameterLinkItem::P_LINK))
                return dynamic_cast<FitParameterItem*>(item);
        }
    }
    return nullptr;
}

QVector<FitParameterItem*> FitParameterContainerItem::fitParameterItems()
{
    QVector<FitParameterItem*> result;
    foreach (SessionItem* parItem, getItems(T_FIT_PARAMETERS))
        result.push_back(dynamic_cast<FitParameterItem*>(parItem));
    return result;
}

bool FitParameterContainerItem::isEmpty()
{
    return getItems(T_FIT_PARAMETERS).isEmpty();
}

//! Propagate values to the corresponding parameter tree items of parameterContainer.

void FitParameterContainerItem::setValuesInParameterContainer(
    const QVector<double>& values, ParameterContainerItem* parameterContainer)
{
    Q_ASSERT(parameterContainer);

    QVector<SessionItem*> fitPars = getItems(FitParameterContainerItem::T_FIT_PARAMETERS);

    int index(0);
    for (int i = 0; i < fitPars.size(); ++i) {
        auto link_list = fitPars[i]->getItems(FitParameterItem::T_LINK);
        if (link_list.size() == 0)
            continue;
        foreach (SessionItem* linkItem, link_list) {
            QString parPath = linkItem->getItemValue(FitParameterLinkItem::P_LINK).toString();
            SessionItem* itemInTuningTree = ModelPath::getItemFromPath(parPath, parameterContainer);
            Q_ASSERT(itemInTuningTree);
            itemInTuningTree->setValue(values[index]);
        }
        index++;
    }
}
