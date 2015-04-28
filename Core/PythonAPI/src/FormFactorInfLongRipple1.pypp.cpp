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
#include "FormFactorInfLongRipple1.pypp.h"

namespace bp = boost::python;

struct FormFactorInfLongRipple1_wrapper : FormFactorInfLongRipple1, bp::wrapper< FormFactorInfLongRipple1 > {

    FormFactorInfLongRipple1_wrapper(double width, double height )
    : FormFactorInfLongRipple1( width, height )
      , bp::wrapper< FormFactorInfLongRipple1 >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FormFactorInfLongRipple1 * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorInfLongRipple1::clone(  );
        }
    }
    
    ::FormFactorInfLongRipple1 * default_clone(  ) const  {
        return FormFactorInfLongRipple1::clone( );
    }

    virtual ::complex_t evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, ::Bin1D const & alpha_f_bin ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
        else{
            return this->FormFactorInfLongRipple1::evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
        }
    }
    
    ::complex_t default_evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, ::Bin1D const & alpha_f_bin ) const  {
        return FormFactorInfLongRipple1::evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorInfLongRipple1::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorInfLongRipple1::evaluate_for_q( boost::ref(q) );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->FormFactorInfLongRipple1::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return FormFactorInfLongRipple1::getHeight( );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else{
            return this->FormFactorInfLongRipple1::getNumberOfStochasticParameters(  );
        }
    }
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return FormFactorInfLongRipple1::getNumberOfStochasticParameters( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->FormFactorInfLongRipple1::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return FormFactorInfLongRipple1::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->FormFactorInfLongRipple1::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return FormFactorInfLongRipple1::getVolume( );
    }

    virtual double getWidth(  ) const  {
        if( bp::override func_getWidth = this->get_override( "getWidth" ) )
            return func_getWidth(  );
        else{
            return this->FormFactorInfLongRipple1::getWidth(  );
        }
    }
    
    double default_getWidth(  ) const  {
        return FormFactorInfLongRipple1::getWidth( );
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

    virtual ::ISample * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ISample::cloneInvertB(  );
        }
    }
    
    ::ISample * default_cloneInvertB(  ) const  {
        return ISample::cloneInvertB( );
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
        if( dynamic_cast< FormFactorInfLongRipple1_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
    }

    virtual void setAmbientMaterial( ::IMaterial const & material ) {
        if( bp::override func_setAmbientMaterial = this->get_override( "setAmbientMaterial" ) )
            func_setAmbientMaterial( boost::ref(material) );
        else{
            this->IFormFactor::setAmbientMaterial( boost::ref(material) );
        }
    }
    
    void default_setAmbientMaterial( ::IMaterial const & material ) {
        IFormFactor::setAmbientMaterial( boost::ref(material) );
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

void register_FormFactorInfLongRipple1_class(){

    { //::FormFactorInfLongRipple1
        typedef bp::class_< FormFactorInfLongRipple1_wrapper, bp::bases< IFormFactorBorn >, std::auto_ptr< FormFactorInfLongRipple1_wrapper >, boost::noncopyable > FormFactorInfLongRipple1_exposer_t;
        FormFactorInfLongRipple1_exposer_t FormFactorInfLongRipple1_exposer = FormFactorInfLongRipple1_exposer_t( "FormFactorInfLongRipple1", "The formfactor for an infinitely long cosine ripple.", bp::init< double, double >(( bp::arg("width"), bp::arg("height") ), "InfLongRipple1 constructor.\n\n:Parameters:\n  - 'width' - of cosine cross section\n  - 'height' - of cosine cross section\n") );
        bp::scope FormFactorInfLongRipple1_scope( FormFactorInfLongRipple1_exposer );
        { //::FormFactorInfLongRipple1::clone
        
            typedef ::FormFactorInfLongRipple1 * ( ::FormFactorInfLongRipple1::*clone_function_type)(  ) const;
            typedef ::FormFactorInfLongRipple1 * ( FormFactorInfLongRipple1_wrapper::*default_clone_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorInfLongRipple1::clone)
                , default_clone_function_type(&FormFactorInfLongRipple1_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorInfLongRipple1::evaluate
        
            typedef ::complex_t ( ::FormFactorInfLongRipple1::*evaluate_function_type)( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            typedef ::complex_t ( FormFactorInfLongRipple1_wrapper::*default_evaluate_function_type)( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::FormFactorInfLongRipple1::evaluate)
                , default_evaluate_function_type(&FormFactorInfLongRipple1_wrapper::default_evaluate)
                , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_f_bin") ) );
        
        }
        { //::FormFactorInfLongRipple1::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorInfLongRipple1::*evaluate_for_q_function_type)( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorInfLongRipple1_wrapper::*default_evaluate_for_q_function_type)( ::cvector_t const & ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorInfLongRipple1::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorInfLongRipple1_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorInfLongRipple1::getHeight
        
            typedef double ( ::FormFactorInfLongRipple1::*getHeight_function_type)(  ) const;
            typedef double ( FormFactorInfLongRipple1_wrapper::*default_getHeight_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::FormFactorInfLongRipple1::getHeight)
                , default_getHeight_function_type(&FormFactorInfLongRipple1_wrapper::default_getHeight) );
        
        }
        { //::FormFactorInfLongRipple1::getNumberOfStochasticParameters
        
            typedef int ( ::FormFactorInfLongRipple1::*getNumberOfStochasticParameters_function_type)(  ) const;
            typedef int ( FormFactorInfLongRipple1_wrapper::*default_getNumberOfStochasticParameters_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getNumberOfStochasticParameters"
                , getNumberOfStochasticParameters_function_type(&::FormFactorInfLongRipple1::getNumberOfStochasticParameters)
                , default_getNumberOfStochasticParameters_function_type(&FormFactorInfLongRipple1_wrapper::default_getNumberOfStochasticParameters) );
        
        }
        { //::FormFactorInfLongRipple1::getRadius
        
            typedef double ( ::FormFactorInfLongRipple1::*getRadius_function_type)(  ) const;
            typedef double ( FormFactorInfLongRipple1_wrapper::*default_getRadius_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::FormFactorInfLongRipple1::getRadius)
                , default_getRadius_function_type(&FormFactorInfLongRipple1_wrapper::default_getRadius) );
        
        }
        { //::FormFactorInfLongRipple1::getVolume
        
            typedef double ( ::FormFactorInfLongRipple1::*getVolume_function_type)(  ) const;
            typedef double ( FormFactorInfLongRipple1_wrapper::*default_getVolume_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::FormFactorInfLongRipple1::getVolume)
                , default_getVolume_function_type(&FormFactorInfLongRipple1_wrapper::default_getVolume) );
        
        }
        { //::FormFactorInfLongRipple1::getWidth
        
            typedef double ( ::FormFactorInfLongRipple1::*getWidth_function_type)(  ) const;
            typedef double ( FormFactorInfLongRipple1_wrapper::*default_getWidth_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getWidth"
                , getWidth_function_type(&::FormFactorInfLongRipple1::getWidth)
                , default_getWidth_function_type(&FormFactorInfLongRipple1_wrapper::default_getWidth) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( FormFactorInfLongRipple1_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FormFactorInfLongRipple1_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( FormFactorInfLongRipple1_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FormFactorInfLongRipple1_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( FormFactorInfLongRipple1_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorInfLongRipple1_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( FormFactorInfLongRipple1_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorInfLongRipple1_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( FormFactorInfLongRipple1_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FormFactorInfLongRipple1_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ISample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( FormFactorInfLongRipple1_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorInfLongRipple1_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( FormFactorInfLongRipple1_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorInfLongRipple1_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::preprocess
        
            typedef bool ( ::ISample::*preprocess_function_type)(  ) ;
            typedef bool ( FormFactorInfLongRipple1_wrapper::*default_preprocess_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "preprocess"
                , preprocess_function_type(&::ISample::preprocess)
                , default_preprocess_function_type(&FormFactorInfLongRipple1_wrapper::default_preprocess) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( FormFactorInfLongRipple1_wrapper::*default_printParameters_function_type)(  ) const;
            
            FormFactorInfLongRipple1_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FormFactorInfLongRipple1_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( FormFactorInfLongRipple1_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorInfLongRipple1_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int,::AttLimits const & );
            
            FormFactorInfLongRipple1_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &FormFactorInfLongRipple1_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer"), bp::arg("limits")=AttLimits::limitless( ) )
                , "main method to register data address in the pool." );
        
        }
        { //::IFormFactor::setAmbientMaterial
        
            typedef void ( ::IFormFactor::*setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( FormFactorInfLongRipple1_wrapper::*default_setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "setAmbientMaterial"
                , setAmbientMaterial_function_type(&::IFormFactor::setAmbientMaterial)
                , default_setAmbientMaterial_function_type(&FormFactorInfLongRipple1_wrapper::default_setAmbientMaterial)
                , ( bp::arg("material") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( FormFactorInfLongRipple1_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FormFactorInfLongRipple1_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( FormFactorInfLongRipple1_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FormFactorInfLongRipple1_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( FormFactorInfLongRipple1_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            FormFactorInfLongRipple1_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&FormFactorInfLongRipple1_wrapper::default_transferToCPP) );
        
        }
    }

}
