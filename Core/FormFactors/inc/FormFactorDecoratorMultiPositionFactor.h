// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorDecoratorMultiPositionFactor.h
//! @brief     Defines class FormFactorDecoratorMultiPositionFactor.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORDECORATORMULTIPOSITIONFACTOR_H_
#define FORMFACTORDECORATORMULTIPOSITIONFACTOR_H_

#include "IFormFactorDecorator.h"

//! Form factor for the same particle at different fixed positions

class FormFactorDecoratorMultiPositionFactor : public IFormFactorDecorator
{
public:
    FormFactorDecoratorMultiPositionFactor(const IFormFactor& form_factor,
            std::vector<kvector_t> positions);
    virtual ~FormFactorDecoratorMultiPositionFactor() {}
    virtual FormFactorDecoratorMultiPositionFactor *clone() const;

    virtual complex_t evaluate(const cvector_t& k_i,
            const Bin1DCVector& k_f_bin, Bin1D alpha_f_bin) const;

    virtual int getNumberOfStochasticParameters() const {
        return mp_form_factor->getNumberOfStochasticParameters();
    }

private:
    complex_t getPositionsFactor(cvector_t q) const;
    std::vector<kvector_t> m_positions;
};

#endif /* FORMFACTORDECORATORMULTIPOSITIONFACTOR_H_ */


