// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
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
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
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
#include "HomogeneousMaterial.pypp.h"

namespace bp = boost::python;

void register_HomogeneousMaterial_class(){

    { //::HomogeneousMaterial
        typedef bp::class_< HomogeneousMaterial, bp::bases< IMaterial > > HomogeneousMaterial_exposer_t;
        HomogeneousMaterial_exposer_t HomogeneousMaterial_exposer = HomogeneousMaterial_exposer_t( "HomogeneousMaterial", bp::init< >() );
        bp::scope HomogeneousMaterial_scope( HomogeneousMaterial_exposer );
        HomogeneousMaterial_exposer.def( bp::init< complex_t const & >(( bp::arg("refractive_index") )) );
        HomogeneousMaterial_exposer.def( bp::init< std::string const &, complex_t const & >(( bp::arg("name"), bp::arg("refractive_index") )) );
        HomogeneousMaterial_exposer.def( bp::init< std::string const &, double, double >(( bp::arg("name"), bp::arg("refractive_index_real"), bp::arg("refractive_index_imag") )) );
        HomogeneousMaterial_exposer.def( bp::init< HomogeneousMaterial const & >(( bp::arg("other") )) );
        { //::HomogeneousMaterial::getRefractiveIndex
        
            typedef ::complex_t ( ::HomogeneousMaterial::*getRefractiveIndex_function_type )(  ) const;
            
            HomogeneousMaterial_exposer.def( 
                "getRefractiveIndex"
                , getRefractiveIndex_function_type( &::HomogeneousMaterial::getRefractiveIndex ) );
        
        }
        { //::HomogeneousMaterial::operator=
        
            typedef ::HomogeneousMaterial & ( ::HomogeneousMaterial::*assign_function_type )( ::HomogeneousMaterial const & ) ;
            
            HomogeneousMaterial_exposer.def( 
                "assign"
                , assign_function_type( &::HomogeneousMaterial::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        { //::HomogeneousMaterial::setRefractiveIndex
        
            typedef void ( ::HomogeneousMaterial::*setRefractiveIndex_function_type )( ::complex_t ) ;
            
            HomogeneousMaterial_exposer.def( 
                "setRefractiveIndex"
                , setRefractiveIndex_function_type( &::HomogeneousMaterial::setRefractiveIndex )
                , ( bp::arg("refractive_index") ) );
        
        }
    }

}
