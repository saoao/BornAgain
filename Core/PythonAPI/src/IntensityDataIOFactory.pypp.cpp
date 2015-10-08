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
#include "IntensityDataIOFactory.pypp.h"

namespace bp = boost::python;

void register_IntensityDataIOFactory_class(){

    { //::IntensityDataIOFactory
        typedef bp::class_< IntensityDataIOFactory > IntensityDataIOFactory_exposer_t;
        IntensityDataIOFactory_exposer_t IntensityDataIOFactory_exposer = IntensityDataIOFactory_exposer_t( "IntensityDataIOFactory", "Reads OutputData from files in different forma." );
        bp::scope IntensityDataIOFactory_scope( IntensityDataIOFactory_exposer );
        { //::IntensityDataIOFactory::readHistogram
        
            typedef ::IHistogram * ( *readHistogram_function_type )( ::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "readHistogram"
                , readHistogram_function_type( &::IntensityDataIOFactory::readHistogram )
                , ( bp::arg("file_name") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IntensityDataIOFactory::readIntensityData
        
            typedef ::IHistogram * ( *readIntensityData_function_type )( ::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "readIntensityData"
                , readIntensityData_function_type( &::IntensityDataIOFactory::readIntensityData )
                , ( bp::arg("file_name") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IntensityDataIOFactory::readOutputData
        
            typedef ::OutputData< double > * ( *readOutputData_function_type )( ::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "readOutputData"
                , readOutputData_function_type( &::IntensityDataIOFactory::readOutputData )
                , ( bp::arg("file_name") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IntensityDataIOFactory::writeHistogram
        
            typedef void ( *writeHistogram_function_type )( ::IHistogram const &,::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "writeHistogram"
                , writeHistogram_function_type( &::IntensityDataIOFactory::writeHistogram )
                , ( bp::arg("histogram"), bp::arg("file_name") ) );
        
        }
        { //::IntensityDataIOFactory::writeIntensityData
        
            typedef void ( *writeIntensityData_function_type )( ::IHistogram const &,::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "writeIntensityData"
                , writeIntensityData_function_type( &::IntensityDataIOFactory::writeIntensityData )
                , ( bp::arg("histogram"), bp::arg("file_name") ) );
        
        }
        { //::IntensityDataIOFactory::writeOutputData
        
            typedef void ( *writeOutputData_function_type )( ::OutputData< double > const &,::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "writeOutputData"
                , writeOutputData_function_type( &::IntensityDataIOFactory::writeOutputData )
                , ( bp::arg("data"), bp::arg("file_name") ) );
        
        }
        IntensityDataIOFactory_exposer.staticmethod( "readHistogram" );
        IntensityDataIOFactory_exposer.staticmethod( "readIntensityData" );
        IntensityDataIOFactory_exposer.staticmethod( "readOutputData" );
        IntensityDataIOFactory_exposer.staticmethod( "writeHistogram" );
        IntensityDataIOFactory_exposer.staticmethod( "writeIntensityData" );
        IntensityDataIOFactory_exposer.staticmethod( "writeOutputData" );
    }

}
