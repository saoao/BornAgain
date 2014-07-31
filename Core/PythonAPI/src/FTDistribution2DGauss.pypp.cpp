// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "FTDistribution2DGauss.pypp.h"

namespace bp = boost::python;

struct FTDistribution2DGauss_wrapper : FTDistribution2DGauss, bp::wrapper< FTDistribution2DGauss > {

    FTDistribution2DGauss_wrapper(FTDistribution2DGauss const & arg )
    : FTDistribution2DGauss( arg )
      , bp::wrapper< FTDistribution2DGauss >(){
        // copy constructor
        
    }

    FTDistribution2DGauss_wrapper(double coherence_length_x, double coherence_length_y )
    : FTDistribution2DGauss( coherence_length_x, coherence_length_y )
      , bp::wrapper< FTDistribution2DGauss >(){
        // constructor
    
    }

    virtual ::FTDistribution2DGauss * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else
            return this->FTDistribution2DGauss::clone(  );
    }
    
    
    ::FTDistribution2DGauss * default_clone(  ) const  {
        return FTDistribution2DGauss::clone( );
    }

    virtual double evaluate( double qx, double qy ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( qx, qy );
        else
            return this->FTDistribution2DGauss::evaluate( qx, qy );
    }
    
    
    double default_evaluate( double qx, double qy ) const  {
        return FTDistribution2DGauss::evaluate( qx, qy );
    }

    virtual double evaluateLattice( double qx, double qy ) const  {
        if( bp::override func_evaluateLattice = this->get_override( "evaluateLattice" ) )
            return func_evaluateLattice( qx, qy );
        else
            return this->FTDistribution2DGauss::evaluateLattice( qx, qy );
    }
    
    
    double default_evaluateLattice( double qx, double qy ) const  {
        return FTDistribution2DGauss::evaluateLattice( qx, qy );
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

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< FTDistribution2DGauss_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
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

void register_FTDistribution2DGauss_class(){

    { //::FTDistribution2DGauss
        typedef bp::class_< FTDistribution2DGauss_wrapper, bp::bases< IFTDistribution2D > > FTDistribution2DGauss_exposer_t;
        FTDistribution2DGauss_exposer_t FTDistribution2DGauss_exposer = FTDistribution2DGauss_exposer_t( "FTDistribution2DGauss", bp::init< double, double >(( bp::arg("coherence_length_x"), bp::arg("coherence_length_y") )) );
        bp::scope FTDistribution2DGauss_scope( FTDistribution2DGauss_exposer );
        { //::FTDistribution2DGauss::clone
        
            typedef ::FTDistribution2DGauss * ( ::FTDistribution2DGauss::*clone_function_type )(  ) const;
            typedef ::FTDistribution2DGauss * ( FTDistribution2DGauss_wrapper::*default_clone_function_type )(  ) const;
            
            FTDistribution2DGauss_exposer.def( 
                "clone"
                , clone_function_type(&::FTDistribution2DGauss::clone)
                , default_clone_function_type(&FTDistribution2DGauss_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FTDistribution2DGauss::evaluate
        
            typedef double ( ::FTDistribution2DGauss::*evaluate_function_type )( double,double ) const;
            typedef double ( FTDistribution2DGauss_wrapper::*default_evaluate_function_type )( double,double ) const;
            
            FTDistribution2DGauss_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::FTDistribution2DGauss::evaluate)
                , default_evaluate_function_type(&FTDistribution2DGauss_wrapper::default_evaluate)
                , ( bp::arg("qx"), bp::arg("qy") ) );
        
        }
        { //::FTDistribution2DGauss::evaluateLattice
        
            typedef double ( ::FTDistribution2DGauss::*evaluateLattice_function_type )( double,double ) const;
            typedef double ( FTDistribution2DGauss_wrapper::*default_evaluateLattice_function_type )( double,double ) const;
            
            FTDistribution2DGauss_exposer.def( 
                "evaluateLattice"
                , evaluateLattice_function_type(&::FTDistribution2DGauss::evaluateLattice)
                , default_evaluateLattice_function_type(&FTDistribution2DGauss_wrapper::default_evaluateLattice)
                , ( bp::arg("qx"), bp::arg("qy") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( FTDistribution2DGauss_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            FTDistribution2DGauss_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FTDistribution2DGauss_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( FTDistribution2DGauss_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            FTDistribution2DGauss_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FTDistribution2DGauss_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( FTDistribution2DGauss_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            FTDistribution2DGauss_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FTDistribution2DGauss_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( FTDistribution2DGauss_wrapper::*default_printParameters_function_type )(  ) const;
            
            FTDistribution2DGauss_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FTDistribution2DGauss_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            FTDistribution2DGauss_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &FTDistribution2DGauss_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( FTDistribution2DGauss_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            FTDistribution2DGauss_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FTDistribution2DGauss_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( FTDistribution2DGauss_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            FTDistribution2DGauss_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FTDistribution2DGauss_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
