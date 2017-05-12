// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/FTDecayFunctionItems.cpp
//! @brief     Implements FTDecayFunction1DItem classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "FTDecayFunctionItems.h"
#include "Units.h"
#include "BornAgainNamespace.h"
#include "GUIHelpers.h"

// --------------------------------------------------------------------------------------------- //

const QString FTDecayFunction1DItem::P_DECAY_LENGTH
    = QString::fromStdString(BornAgain::DecayLength);

FTDecayFunction1DItem::FTDecayFunction1DItem(const QString& name)
    : SessionItem(name)
{ }

// --------------------------------------------------------------------------------------------- //

FTDecayFunction1DCauchyItem::FTDecayFunction1DCauchyItem()
    : FTDecayFunction1DItem(Constants::FTDecayFunction1DCauchyType)
{
    addProperty(P_DECAY_LENGTH, 1000.0);
}

std::unique_ptr<IFTDecayFunction1D> FTDecayFunction1DCauchyItem::createFTDecayFunction() const
{
    return GUIHelpers::make_unique<FTDecayFunction1DCauchy>(
        getItemValue(P_DECAY_LENGTH).toDouble());
}

// --------------------------------------------------------------------------------------------- //

FTDecayFunction1DGaussItem::FTDecayFunction1DGaussItem()
    : FTDecayFunction1DItem(Constants::FTDecayFunction1DGaussType)
{
    addProperty(P_DECAY_LENGTH, 1000.0);
}

std::unique_ptr<IFTDecayFunction1D> FTDecayFunction1DGaussItem::createFTDecayFunction() const
{
    return GUIHelpers::make_unique<FTDecayFunction1DGauss>(getItemValue(P_DECAY_LENGTH).toDouble());
}

// --------------------------------------------------------------------------------------------- //

FTDecayFunction1DTriangleItem::FTDecayFunction1DTriangleItem()
    : FTDecayFunction1DItem(Constants::FTDecayFunction1DTriangleType)
{
    addProperty(P_DECAY_LENGTH, 1000.0);
}

std::unique_ptr<IFTDecayFunction1D> FTDecayFunction1DTriangleItem::createFTDecayFunction() const
{
    return GUIHelpers::make_unique<FTDecayFunction1DTriangle>(
        getItemValue(P_DECAY_LENGTH).toDouble());
}

// --------------------------------------------------------------------------------------------- //

const QString FTDecayFunction1DVoigtItem::P_ETA = QString::fromStdString(BornAgain::Eta);

FTDecayFunction1DVoigtItem::FTDecayFunction1DVoigtItem()
    : FTDecayFunction1DItem(Constants::FTDecayFunction1DVoigtType)
{
    addProperty(P_DECAY_LENGTH, 1000.0);
    addProperty(P_ETA, 0.5)->setLimits(RealLimits::limited(0.0, 1.0));
}

std::unique_ptr<IFTDecayFunction1D> FTDecayFunction1DVoigtItem::createFTDecayFunction() const
{
    return GUIHelpers::make_unique<FTDecayFunction1DVoigt>(
                getItemValue(P_DECAY_LENGTH).toDouble(),
                getItemValue(P_ETA).toDouble() );
}

// --------------------------------------------------------------------------------------------- //

const QString FTDecayFunction2DItem::P_DECAY_LENGTH_X
    = QString::fromStdString(BornAgain::DecayLengthX);
const QString FTDecayFunction2DItem::P_DECAY_LENGTH_Y
    = QString::fromStdString(BornAgain::DecayLengthY);
const QString FTDecayFunction2DItem::P_GAMMA
    = QString::fromStdString(BornAgain::Gamma);
const QString FTDecayFunction2DItem::P_DELTA
    = QString::fromStdString(BornAgain::Delta);

FTDecayFunction2DItem::FTDecayFunction2DItem(const QString& name)
    : SessionItem(name)
{
}

void FTDecayFunction2DItem::add_decay_property()
{
    addProperty(P_DECAY_LENGTH_X, 1000.0);
    addProperty(P_DECAY_LENGTH_Y, 1000.0);
}

void FTDecayFunction2DItem::add_gammadelta_property()
{
    addProperty(P_GAMMA, 0.0);
    addProperty(P_DELTA, 90.0);
}

// --------------------------------------------------------------------------------------------- //

FTDecayFunction2DCauchyItem::FTDecayFunction2DCauchyItem()
    : FTDecayFunction2DItem(Constants::FTDecayFunction2DCauchyType)
{
    add_decay_property();
    add_gammadelta_property();
}

std::unique_ptr<IFTDecayFunction2D> FTDecayFunction2DCauchyItem::createFTDecayFunction() const
{
    auto result = GUIHelpers::make_unique<FTDecayFunction2DCauchy>(
        getItemValue(P_DECAY_LENGTH_X).toDouble(), getItemValue(P_DECAY_LENGTH_Y).toDouble(),
        Units::deg2rad(getItemValue(P_GAMMA).toDouble()),
        Units::deg2rad(getItemValue(P_DELTA).toDouble()));

    return std::move(result);
}

// --------------------------------------------------------------------------------------------- //

FTDecayFunction2DGaussItem::FTDecayFunction2DGaussItem()
    : FTDecayFunction2DItem(Constants::FTDecayFunction2DGaussType)
{
    add_decay_property();
    add_gammadelta_property();
}

std::unique_ptr<IFTDecayFunction2D> FTDecayFunction2DGaussItem::createFTDecayFunction() const
{
    auto result = GUIHelpers::make_unique<FTDecayFunction2DGauss>(
        getItemValue(P_DECAY_LENGTH_X).toDouble(), getItemValue(P_DECAY_LENGTH_Y).toDouble(),
        Units::deg2rad(getItemValue(P_GAMMA).toDouble()),
        Units::deg2rad(getItemValue(P_DELTA).toDouble()));

    return std::move(result);
}

// --------------------------------------------------------------------------------------------- //

const QString FTDecayFunction2DVoigtItem::P_ETA = QString::fromStdString(BornAgain::Eta);

FTDecayFunction2DVoigtItem::FTDecayFunction2DVoigtItem()
    : FTDecayFunction2DItem(Constants::FTDecayFunction2DVoigtType)
{
    add_decay_property();
    addProperty(P_ETA, 0.5)->setLimits(RealLimits::limited(0.0, 1.0));
    add_gammadelta_property();
}

std::unique_ptr<IFTDecayFunction2D> FTDecayFunction2DVoigtItem::createFTDecayFunction() const
{
    auto result = GUIHelpers::make_unique<FTDecayFunction2DVoigt>(
        getItemValue(P_DECAY_LENGTH_X).toDouble(), getItemValue(P_DECAY_LENGTH_Y).toDouble(),
        getItemValue(P_ETA).toDouble(),
        Units::deg2rad(getItemValue(P_GAMMA).toDouble()),
        Units::deg2rad(getItemValue(P_DELTA).toDouble()));

    return std::move(result);
}