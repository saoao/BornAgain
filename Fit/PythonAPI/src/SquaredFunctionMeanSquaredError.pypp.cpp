// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonFitAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "SquaredFunctionMeanSquaredError.pypp.h"

namespace bp = boost::python;

struct SquaredFunctionMeanSquaredError_wrapper : SquaredFunctionMeanSquaredError, bp::wrapper< SquaredFunctionMeanSquaredError > {

    SquaredFunctionMeanSquaredError_wrapper( )
    : SquaredFunctionMeanSquaredError( )
      , bp::wrapper< SquaredFunctionMeanSquaredError >(){
        // null constructor
    
    }

    virtual double calculateSquaredDifference( double real_value, double simulated_value ) const  {
        if( bp::override func_calculateSquaredDifference = this->get_override( "calculateSquaredDifference" ) )
            return func_calculateSquaredDifference( real_value, simulated_value );
        else
            return this->SquaredFunctionMeanSquaredError::calculateSquaredDifference( real_value, simulated_value );
    }
    
    
    double default_calculateSquaredDifference( double real_value, double simulated_value ) const  {
        return SquaredFunctionMeanSquaredError::calculateSquaredDifference( real_value, simulated_value );
    }

    virtual double calculateSquaredError( double real_value, double simulated_value ) const  {
        if( bp::override func_calculateSquaredError = this->get_override( "calculateSquaredError" ) )
            return func_calculateSquaredError( real_value, simulated_value );
        else
            return this->SquaredFunctionMeanSquaredError::calculateSquaredError( real_value, simulated_value );
    }
    
    
    double default_calculateSquaredError( double real_value, double simulated_value ) const  {
        return SquaredFunctionMeanSquaredError::calculateSquaredError( real_value, simulated_value );
    }

    virtual ::SquaredFunctionMeanSquaredError * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else
            return this->SquaredFunctionMeanSquaredError::clone(  );
    }
    
    
    ::SquaredFunctionMeanSquaredError * default_clone(  ) const  {
        return SquaredFunctionMeanSquaredError::clone( );
    }

};

void register_SquaredFunctionMeanSquaredError_class(){

    { //::SquaredFunctionMeanSquaredError
        typedef bp::class_< SquaredFunctionMeanSquaredError_wrapper, bp::bases< ISquaredFunction >, boost::noncopyable > SquaredFunctionMeanSquaredError_exposer_t;
        SquaredFunctionMeanSquaredError_exposer_t SquaredFunctionMeanSquaredError_exposer = SquaredFunctionMeanSquaredError_exposer_t( "SquaredFunctionMeanSquaredError", bp::init< >() );
        bp::scope SquaredFunctionMeanSquaredError_scope( SquaredFunctionMeanSquaredError_exposer );
        { //::SquaredFunctionMeanSquaredError::calculateSquaredDifference
        
            typedef double ( ::SquaredFunctionMeanSquaredError::*calculateSquaredDifference_function_type )( double,double ) const;
            typedef double ( SquaredFunctionMeanSquaredError_wrapper::*default_calculateSquaredDifference_function_type )( double,double ) const;
            
            SquaredFunctionMeanSquaredError_exposer.def( 
                "calculateSquaredDifference"
                , calculateSquaredDifference_function_type(&::SquaredFunctionMeanSquaredError::calculateSquaredDifference)
                , default_calculateSquaredDifference_function_type(&SquaredFunctionMeanSquaredError_wrapper::default_calculateSquaredDifference)
                , ( bp::arg("real_value"), bp::arg("simulated_value") ) );
        
        }
        { //::SquaredFunctionMeanSquaredError::calculateSquaredError
        
            typedef double ( ::SquaredFunctionMeanSquaredError::*calculateSquaredError_function_type )( double,double ) const;
            typedef double ( SquaredFunctionMeanSquaredError_wrapper::*default_calculateSquaredError_function_type )( double,double ) const;
            
            SquaredFunctionMeanSquaredError_exposer.def( 
                "calculateSquaredError"
                , calculateSquaredError_function_type(&::SquaredFunctionMeanSquaredError::calculateSquaredError)
                , default_calculateSquaredError_function_type(&SquaredFunctionMeanSquaredError_wrapper::default_calculateSquaredError)
                , ( bp::arg("real_value"), bp::arg("simulated_value") ) );
        
        }
        { //::SquaredFunctionMeanSquaredError::clone
        
            typedef ::SquaredFunctionMeanSquaredError * ( ::SquaredFunctionMeanSquaredError::*clone_function_type )(  ) const;
            typedef ::SquaredFunctionMeanSquaredError * ( SquaredFunctionMeanSquaredError_wrapper::*default_clone_function_type )(  ) const;
            
            SquaredFunctionMeanSquaredError_exposer.def( 
                "clone"
                , clone_function_type(&::SquaredFunctionMeanSquaredError::clone)
                , default_clone_function_type(&SquaredFunctionMeanSquaredError_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
    }

}
