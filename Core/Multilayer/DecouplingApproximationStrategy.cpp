// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Multilayer/DecouplingApproximationStrategy.cpp
//! @brief     Implements class DecouplingApproximationStrategy.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "DecouplingApproximationStrategy.h"
#include "Exceptions.h"
#include "FormFactorCoherentSum.h"
#include "IInterferenceFunction.h"
#include "MathFunctions.h"
#include "RealParameter.h"
#include "SimulationElement.h"

DecouplingApproximationStrategy::DecouplingApproximationStrategy(
        SimulationOptions sim_params, bool polarized)
    : IInterferenceFunctionStrategy(sim_params, polarized)
{}

//! Returns the total incoherent and coherent scattering intensity for given kf and
//! for one particle layout (implied by the given particle form factors).
//! This is the scalar version
double DecouplingApproximationStrategy::scalarCalculation(
        const SimulationElement& sim_element) const
{
    double intensity = 0.0;
    complex_t amplitude = complex_t(0.0, 0.0);
    auto precomputed_ff = precomputeScalar(sim_element, m_formfactor_wrappers);
    for (size_t i = 0; i < m_formfactor_wrappers.size(); ++i) {
        complex_t ff = precomputed_ff[i];
        if (std::isnan(ff.real()))
            throw Exceptions::RuntimeErrorException(
                "DecouplingApproximationStrategy::scalarCalculation() -> Error! Amplitude is NaN");
        double fraction = m_formfactor_wrappers[i]->relativeAbundance();
        amplitude += fraction * ff;
        intensity += fraction * std::norm(ff);
    }
    double amplitude_norm = std::norm(amplitude);
    double itf_function = mP_iff->evaluate(sim_element.getMeanQ());
    return intensity + amplitude_norm * (itf_function - 1.0);
}

//! This is the polarized version
double DecouplingApproximationStrategy::polarizedCalculation(
        const SimulationElement& sim_element) const
{
    Eigen::Matrix2cd mean_intensity = Eigen::Matrix2cd::Zero();
    Eigen::Matrix2cd mean_amplitude = Eigen::Matrix2cd::Zero();

    auto precomputed_ff = precomputePolarized(sim_element, m_formfactor_wrappers);
    for (size_t i = 0; i < m_formfactor_wrappers.size(); ++i) {
        Eigen::Matrix2cd ff = precomputed_ff[i];
        if (!ff.allFinite())
            throw Exceptions::RuntimeErrorException(
                "DecouplingApproximationStrategy::polarizedCalculation() -> "
                "Error! Form factor contains NaN or infinite");
        double fraction = m_formfactor_wrappers[i]->relativeAbundance();
        mean_amplitude += fraction * ff;
        mean_intensity += fraction * (ff * sim_element.getPolarization() * ff.adjoint());
    }
    Eigen::Matrix2cd amplitude_matrix = sim_element.getAnalyzerOperator() * mean_amplitude
            * sim_element.getPolarization() * mean_amplitude.adjoint();
    Eigen::Matrix2cd intensity_matrix = sim_element.getAnalyzerOperator() * mean_intensity;
    double amplitude_trace = std::abs(amplitude_matrix.trace());
    double intensity_trace = std::abs(intensity_matrix.trace());
    double itf_function = mP_iff->evaluate(sim_element.getMeanQ());
    return intensity_trace + amplitude_trace * (itf_function - 1.0);
}
