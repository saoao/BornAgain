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
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "RotationX.pypp.h"

namespace bp = boost::python;

struct RotationX_wrapper : RotationX, bp::wrapper< RotationX > {

    RotationX_wrapper(double angle )
    : RotationX( angle )
      , bp::wrapper< RotationX >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::RotationX * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->RotationX::clone(  );
        }
    }
    
    ::RotationX * default_clone(  ) const  {
        return RotationX::clone( );
    }

    virtual ::RotationX * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->RotationX::cloneInvertB(  );
        }
    }
    
    ::RotationX * default_cloneInvertB(  ) const  {
        return RotationX::cloneInvertB( );
    }

    virtual ::RotationX * createInverse(  ) const  {
        if( bp::override func_createInverse = this->get_override( "createInverse" ) )
            return func_createInverse(  );
        else{
            return this->RotationX::createInverse(  );
        }
    }
    
    ::RotationX * default_createInverse(  ) const  {
        return RotationX::createInverse( );
    }

    virtual ::Geometry::Transform3D getTransform3D(  ) const  {
        if( bp::override func_getTransform3D = this->get_override( "getTransform3D" ) )
            return func_getTransform3D(  );
        else{
            return this->RotationX::getTransform3D(  );
        }
    }
    
    ::Geometry::Transform3D default_getTransform3D(  ) const  {
        return RotationX::getTransform3D( );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ISample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ISample::getCompositeSample( );
    }

    virtual bool preprocess(  ) {
        if( bp::override func_preprocess = this->get_override( "preprocess" ) )
            return func_preprocess(  );
        else{
            return this->ISample::preprocess(  );
        }
    }
    
    bool default_preprocess(  ) {
        return ISample::preprocess( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual void registerParameter( ::std::string const & name, double * parpointer, ::AttLimits const & limits=AttLimits::limitless( ) ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer, limits );
        }
        else{
            IParameterized::registerParameter( name, parpointer, boost::ref(limits) );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer, ::AttLimits const & limits=AttLimits::limitless( ) ){
        if( dynamic_cast< RotationX_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_RotationX_class(){

    { //::RotationX
        typedef bp::class_< RotationX_wrapper, bp::bases< IRotation >, std::auto_ptr< RotationX_wrapper >, boost::noncopyable > RotationX_exposer_t;
        RotationX_exposer_t RotationX_exposer = RotationX_exposer_t( "RotationX", "", bp::init< double >(( bp::arg("angle") ), "") );
        bp::scope RotationX_scope( RotationX_exposer );
        { //::RotationX::clone
        
            typedef ::RotationX * ( ::RotationX::*clone_function_type)(  ) const;
            typedef ::RotationX * ( RotationX_wrapper::*default_clone_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "clone"
                , clone_function_type(&::RotationX::clone)
                , default_clone_function_type(&RotationX_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::RotationX::cloneInvertB
        
            typedef ::RotationX * ( ::RotationX::*cloneInvertB_function_type)(  ) const;
            typedef ::RotationX * ( RotationX_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::RotationX::cloneInvertB)
                , default_cloneInvertB_function_type(&RotationX_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::RotationX::createInverse
        
            typedef ::RotationX * ( ::RotationX::*createInverse_function_type)(  ) const;
            typedef ::RotationX * ( RotationX_wrapper::*default_createInverse_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "createInverse"
                , createInverse_function_type(&::RotationX::createInverse)
                , default_createInverse_function_type(&RotationX_wrapper::default_createInverse)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::RotationX::getAngle
        
            typedef double ( ::RotationX::*getAngle_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "getAngle"
                , getAngle_function_type( &::RotationX::getAngle )
                , "" );
        
        }
        { //::RotationX::getTransform3D
        
            typedef ::Geometry::Transform3D ( ::RotationX::*getTransform3D_function_type)(  ) const;
            typedef ::Geometry::Transform3D ( RotationX_wrapper::*default_getTransform3D_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "getTransform3D"
                , getTransform3D_function_type(&::RotationX::getTransform3D)
                , default_getTransform3D_function_type(&RotationX_wrapper::default_getTransform3D) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( RotationX_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&RotationX_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( RotationX_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&RotationX_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( RotationX_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&RotationX_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( RotationX_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&RotationX_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ISample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( RotationX_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&RotationX_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( RotationX_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&RotationX_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::preprocess
        
            typedef bool ( ::ISample::*preprocess_function_type)(  ) ;
            typedef bool ( RotationX_wrapper::*default_preprocess_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "preprocess"
                , preprocess_function_type(&::ISample::preprocess)
                , default_preprocess_function_type(&RotationX_wrapper::default_preprocess) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( RotationX_wrapper::*default_printParameters_function_type)(  ) const;
            
            RotationX_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&RotationX_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( RotationX_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&RotationX_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int,::AttLimits const & );
            
            RotationX_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &RotationX_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer"), bp::arg("limits")=AttLimits::limitless( ) )
                , "    //! main method to register data address in the pool" );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( RotationX_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            RotationX_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&RotationX_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( RotationX_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&RotationX_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( RotationX_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            RotationX_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&RotationX_wrapper::default_transferToCPP) );
        
        }
    }

}
