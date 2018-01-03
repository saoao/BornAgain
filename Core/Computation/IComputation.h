// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Computation/IComputation.h
//! @brief     Defines interface IComputation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef ICOMPUTATION_H
#define ICOMPUTATION_H

#include "ComputationStatus.h"
#include "SimulationOptions.h"
#include <memory>
#include <vector>

class MultiLayer;
class ProgressHandler;
class SimulationElement;

//! Interface for a single-threaded computation with given range of SimulationElements
//! and ProgressHandler.
//!
//! Controlled by the multi-threading machinery in Simulation::runSingleSimulation().
//!
//! @ingroup algorithms_internal

class IComputation
{
public:
    IComputation(const SimulationOptions& options, ProgressHandler& progress,
                 const std::vector<SimulationElement>::iterator& start,
                 const std::vector<SimulationElement>::iterator& end,
                 const MultiLayer& sample);
    virtual ~IComputation();

    void run();

    bool isCompleted() const { return m_status.isCompleted(); }
    std::string errorMessage() const { return m_status.errorMessage(); }

protected:
    virtual void runProtected() = 0;

    SimulationOptions m_sim_options;
    ProgressHandler* m_progress;
    std::vector<SimulationElement>::iterator m_begin_it, m_end_it; //!< these iterators define the span of detector bins this simulation will work on
    ComputationStatus m_status;
    std::unique_ptr<MultiLayer> mP_multi_layer;
};

#endif // ICOMPUTATION_H
