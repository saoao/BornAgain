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
#include "IntensityScaleAndShiftNormalizer.pypp.h"

namespace bp = boost::python;

struct IntensityScaleAndShiftNormalizer_wrapper : IntensityScaleAndShiftNormalizer, bp::wrapper< IntensityScaleAndShiftNormalizer > {

    IntensityScaleAndShiftNormalizer_wrapper(IntensityScaleAndShiftNormalizer const & arg )
    : IntensityScaleAndShiftNormalizer( arg )
      , bp::wrapper< IntensityScaleAndShiftNormalizer >(){
        // copy constructor
        
    }

    IntensityScaleAndShiftNormalizer_wrapper(double scale=1.0e+0, double shift=0.0 )
    : IntensityScaleAndShiftNormalizer( scale, shift )
      , bp::wrapper< IntensityScaleAndShiftNormalizer >(){
        // constructor
    
    }

    virtual ::IntensityScaleAndShiftNormalizer * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else
            return this->IntensityScaleAndShiftNormalizer::clone(  );
    }
    
    
    ::IntensityScaleAndShiftNormalizer * default_clone(  ) const  {
        return IntensityScaleAndShiftNormalizer::clone( );
    }

    virtual void setMaximumIntensity( double max_intensity ) {
        if( bp::override func_setMaximumIntensity = this->get_override( "setMaximumIntensity" ) )
            func_setMaximumIntensity( max_intensity );
        else
            this->IntensityScaleAndShiftNormalizer::setMaximumIntensity( max_intensity );
    }
    
    
    void default_setMaximumIntensity( double max_intensity ) {
        IntensityScaleAndShiftNormalizer::setMaximumIntensity( max_intensity );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else
            return this->IParameterized::areParametersChanged(  );
    }
    
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else
            this->IParameterized::clearParameterPool(  );
    }
    
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::OutputData< double > * createNormalizedData( ::OutputData< double > const & data ) const  {
        if( bp::override func_createNormalizedData = this->get_override( "createNormalizedData" ) )
            return func_createNormalizedData( boost::ref(data) );
        else
            return this->IntensityNormalizer::createNormalizedData( boost::ref(data) );
    }
    
    
    ::OutputData< double > * default_createNormalizedData( ::OutputData< double > const & data ) const  {
        return IntensityNormalizer::createNormalizedData( boost::ref(data) );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else
            return this->IParameterized::createParameterTree(  );
    }
    
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else
            this->IParameterized::printParameters(  );
    }
    
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else
            return this->IParameterized::setParameterValue( name, value );
    }
    
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else
            this->IParameterized::setParametersAreChanged(  );
    }
    
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_IntensityScaleAndShiftNormalizer_class(){

    { //::IntensityScaleAndShiftNormalizer
        typedef bp::class_< IntensityScaleAndShiftNormalizer_wrapper, bp::bases< IntensityNormalizer > > IntensityScaleAndShiftNormalizer_exposer_t;
        IntensityScaleAndShiftNormalizer_exposer_t IntensityScaleAndShiftNormalizer_exposer = IntensityScaleAndShiftNormalizer_exposer_t( "IntensityScaleAndShiftNormalizer", bp::init< bp::optional< double, double > >(( bp::arg("scale")=1.0e+0, bp::arg("shift")=0.0 )) );
        bp::scope IntensityScaleAndShiftNormalizer_scope( IntensityScaleAndShiftNormalizer_exposer );
        { //::IntensityScaleAndShiftNormalizer::clone
        
            typedef ::IntensityScaleAndShiftNormalizer * ( ::IntensityScaleAndShiftNormalizer::*clone_function_type )(  ) const;
            typedef ::IntensityScaleAndShiftNormalizer * ( IntensityScaleAndShiftNormalizer_wrapper::*default_clone_function_type )(  ) const;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "clone"
                , clone_function_type(&::IntensityScaleAndShiftNormalizer::clone)
                , default_clone_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IntensityScaleAndShiftNormalizer::setMaximumIntensity
        
            typedef void ( ::IntensityScaleAndShiftNormalizer::*setMaximumIntensity_function_type )( double ) ;
            typedef void ( IntensityScaleAndShiftNormalizer_wrapper::*default_setMaximumIntensity_function_type )( double ) ;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "setMaximumIntensity"
                , setMaximumIntensity_function_type(&::IntensityScaleAndShiftNormalizer::setMaximumIntensity)
                , default_setMaximumIntensity_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_setMaximumIntensity)
                , ( bp::arg("max_intensity") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( IntensityScaleAndShiftNormalizer_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( IntensityScaleAndShiftNormalizer_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_clearParameterPool) );
        
        }
        { //::IntensityNormalizer::createNormalizedData
        
            typedef ::OutputData< double > * ( ::IntensityNormalizer::*createNormalizedData_function_type )( ::OutputData< double > const & ) const;
            typedef ::OutputData< double > * ( IntensityScaleAndShiftNormalizer_wrapper::*default_createNormalizedData_function_type )( ::OutputData< double > const & ) const;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "createNormalizedData"
                , createNormalizedData_function_type(&::IntensityNormalizer::createNormalizedData)
                , default_createNormalizedData_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_createNormalizedData)
                , ( bp::arg("data") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( IntensityScaleAndShiftNormalizer_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( IntensityScaleAndShiftNormalizer_wrapper::*default_printParameters_function_type )(  ) const;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( IntensityScaleAndShiftNormalizer_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( IntensityScaleAndShiftNormalizer_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            IntensityScaleAndShiftNormalizer_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&IntensityScaleAndShiftNormalizer_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
