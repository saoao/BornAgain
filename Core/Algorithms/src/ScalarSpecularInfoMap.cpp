// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/src/ScalarSpecularInfoMap.cpp
//! @brief     Implements class ScalarSpecularInfoMap.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ScalarSpecularInfoMap.h"
#include "SpecularMatrix.h"


ScalarSpecularInfoMap::ScalarSpecularInfoMap(const MultiLayer *multilayer,
                                             int layer, double wavelength)
    : mp_multilayer(multilayer)
    , m_layer(layer)
    , m_wavelength(wavelength)
{
}

const ScalarRTCoefficients *ScalarSpecularInfoMap::getCoefficients(
        double alpha_f, double phi_f) const
{
    (void)phi_f;
    SpecularMatrix specular_calculator;
    SpecularMatrix::MultiLayerCoeff_t coeffs;
    kvector_t kvec;
    // phi has no effect on R,T, so just pass zero:
    kvec.setLambdaAlphaPhi(m_wavelength, -alpha_f, 0.0);
    specular_calculator.execute(*mp_multilayer, kvec, coeffs);
    return new ScalarRTCoefficients(coeffs[m_layer]);
}