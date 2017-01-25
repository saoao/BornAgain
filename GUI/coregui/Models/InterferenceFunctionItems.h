// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/InterferenceFunctionItems.h
//! @brief     Defines InterferenceFunctionItems's classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef INTERFERENCEFUNCTIONITEMS_H
#define INTERFERENCEFUNCTIONITEMS_H

#include "SessionGraphicsItem.h"
class InterferenceFunction;

class BA_CORE_API_ InterferenceFunctionItem  : public SessionGraphicsItem
{
public:
    explicit InterferenceFunctionItem(const QString& modelType);
    virtual ~InterferenceFunctionItem();
    virtual std::unique_ptr<InterferenceFunction> createInterferenceFunction() const=0;
};

class BA_CORE_API_ InterferenceFunctionRadialParaCrystalItem : public InterferenceFunctionItem
{

public:
    static const QString P_PEAK_DISTANCE;
    static const QString P_DAMPING_LENGTH;
    static const QString P_DOMAIN_SIZE;
    static const QString P_KAPPA;
    static const QString P_PDF;
    InterferenceFunctionRadialParaCrystalItem();
    std::unique_ptr<InterferenceFunction> createInterferenceFunction() const;
};

class BA_CORE_API_ InterferenceFunction2DParaCrystalItem : public InterferenceFunctionItem
{

public:
    static const QString P_ROTATION_ANGLE;
    static const QString P_DAMPING_LENGTH;
    static const QString P_DOMAIN_SIZE1;
    static const QString P_DOMAIN_SIZE2;
    static const QString P_XI_INTEGRATION;
    static const QString P_PDF1;
    static const QString P_PDF2;
    InterferenceFunction2DParaCrystalItem();
    std::unique_ptr<InterferenceFunction> createInterferenceFunction() const;
};

class BA_CORE_API_ InterferenceFunction1DLatticeItem : public InterferenceFunctionItem
{

public:
    static const QString P_LENGTH;
    static const QString P_ROTATION_ANGLE;
    static const QString P_DECAY_FUNCTION;
    InterferenceFunction1DLatticeItem();
    std::unique_ptr<InterferenceFunction> createInterferenceFunction() const;
};

class BA_CORE_API_ InterferenceFunction2DLatticeItem : public InterferenceFunctionItem
{

public:
    static const QString P_LATTICE_TYPE;
    static const QString P_ROTATION_ANGLE;
    static const QString P_DECAY_FUNCTION;
    InterferenceFunction2DLatticeItem();
    std::unique_ptr<InterferenceFunction> createInterferenceFunction() const;
};

#endif // INTERFERENCEFUNCTIONITEMS_H
