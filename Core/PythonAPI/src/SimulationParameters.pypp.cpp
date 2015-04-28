// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "SimulationParameters.pypp.h"

namespace bp = boost::python;

void register_SimulationParameters_class(){

    { //::SimulationParameters
        typedef bp::class_< SimulationParameters > SimulationParameters_exposer_t;
        SimulationParameters_exposer_t SimulationParameters_exposer = SimulationParameters_exposer_t( "SimulationParameters", "Collect the different options for simulation.", bp::init< >() );
        bp::scope SimulationParameters_scope( SimulationParameters_exposer );
        SimulationParameters_exposer.def_readwrite( "m_mc_integration", &SimulationParameters::m_mc_integration );
        SimulationParameters_exposer.def_readwrite( "m_mc_points", &SimulationParameters::m_mc_points );
    }

}
