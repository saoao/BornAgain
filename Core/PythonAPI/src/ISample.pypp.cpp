// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Experiment.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "GISASExperiment.h"
#include "HomogeneousMaterial.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "InterferenceFunctionNone.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Lattice.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "Crystal.h"
#include "ParticleDecoration.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "ParticleInfo.h"
#include "DiffuseParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Transform3D.h"
#include "Units.h"
#include "Types.h"
#include "ISample.pypp.h"

namespace bp = boost::python;

struct ISample_wrapper : ISample, bp::wrapper< ISample > {

    ISample_wrapper( )
    : ISample( )
      , bp::wrapper< ISample >(){
        // null constructor
    
    }

    ISample_wrapper(::ISample const & other )
    : ISample( boost::ref(other) )
      , bp::wrapper< ISample >(){
        // copy constructor
    
    }

    virtual ::ISample * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->ISample::clone(  );
        }
    }
    
    ::ISample * default_clone(  ) const  {
        return ISample::clone( );
    }

    virtual void print_structure(  ) {
        if( bp::override func_print_structure = this->get_override( "print_structure" ) )
            func_print_structure(  );
        else{
            this->ISample::print_structure(  );
        }
    }
    
    void default_print_structure(  ) {
        ISample::print_structure( );
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

};

void register_ISample_class(){

    { //::ISample
        typedef bp::class_< ISample_wrapper, bp::bases< IParameterized > > ISample_exposer_t;
        ISample_exposer_t ISample_exposer = ISample_exposer_t( "ISample", bp::init< >() );
        bp::scope ISample_scope( ISample_exposer );
        ISample_exposer.def( bp::init< ISample const & >(( bp::arg("other") )) );
        { //::ISample::clone
        
            typedef ::ISample * ( ::ISample::*clone_function_type )(  ) const;
            typedef ::ISample * ( ISample_wrapper::*default_clone_function_type )(  ) const;
            
            ISample_exposer.def( 
                "clone"
                , clone_function_type(&::ISample::clone)
                , default_clone_function_type(&ISample_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ISample::operator=
        
            typedef ::ISample & ( ::ISample::*assign_function_type )( ::ISample const & ) ;
            
            ISample_exposer.def( 
                "assign"
                , assign_function_type( &::ISample::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        { //::ISample::print_structure
        
            typedef void ( ::ISample::*print_structure_function_type )(  ) ;
            typedef void ( ISample_wrapper::*default_print_structure_function_type )(  ) ;
            
            ISample_exposer.def( 
                "print_structure"
                , print_structure_function_type(&::ISample::print_structure)
                , default_print_structure_function_type(&ISample_wrapper::default_print_structure) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( ISample_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            ISample_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&ISample_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( ISample_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            ISample_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&ISample_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( ISample_wrapper::*default_printParameters_function_type )(  ) const;
            
            ISample_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&ISample_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( ISample_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            ISample_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&ISample_wrapper::default_setParametersAreChanged) );
        
        }
        ISample_exposer.def( bp::self_ns::str( bp::self ) );
    }

}