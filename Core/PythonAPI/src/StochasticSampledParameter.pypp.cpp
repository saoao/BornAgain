// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorParallelepiped.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "Lattice2DIFParameters.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "StochasticDoubleGate.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "StochasticSampledParameter.pypp.h"

namespace bp = boost::python;

struct StochasticSampledParameter_wrapper : StochasticSampledParameter, bp::wrapper< StochasticSampledParameter > {

    StochasticSampledParameter_wrapper(::StochasticParameter< double > const & par, ::size_t nbins, double xmin, double xmax )
    : StochasticSampledParameter( boost::ref(par), nbins, xmin, xmax )
      , bp::wrapper< StochasticSampledParameter >(){
        // constructor
    
    }

    StochasticSampledParameter_wrapper(::StochasticParameter< double > const & par, ::size_t nbins, int nfwhm=3 )
    : StochasticSampledParameter( boost::ref(par), nbins, nfwhm )
      , bp::wrapper< StochasticSampledParameter >(){
        // constructor
    
    }

    virtual ::StochasticSampledParameter * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->StochasticSampledParameter::clone(  );
        }
    }
    
    ::StochasticSampledParameter * default_clone(  ) const  {
        return StochasticSampledParameter::clone( );
    }

    virtual double probabilityDensity( double value ) const  {
        if( bp::override func_probabilityDensity = this->get_override( "probabilityDensity" ) )
            return func_probabilityDensity( value );
        else{
            return this->StochasticSampledParameter::probabilityDensity( value );
        }
    }
    
    double default_probabilityDensity( double value ) const  {
        return StochasticSampledParameter::probabilityDensity( value );
    }

    virtual void setToRandom(  ) {
        if( bp::override func_setToRandom = this->get_override( "setToRandom" ) )
            func_setToRandom(  );
        else{
            this->StochasticSampledParameter::setToRandom(  );
        }
    }
    
    void default_setToRandom(  ) {
        StochasticSampledParameter::setToRandom( );
    }

    virtual double getFWHM(  ) const  {
        if( bp::override func_getFWHM = this->get_override( "getFWHM" ) )
            return func_getFWHM(  );
        else{
            return this->StochasticParameter< double >::getFWHM(  );
        }
    }
    
    double default_getFWHM(  ) const  {
        return StochasticParameter< double >::getFWHM( );
    }

    virtual double getRandom(  ) {
        if( bp::override func_getRandom = this->get_override( "getRandom" ) )
            return func_getRandom(  );
        else{
            return this->StochasticParameter< double >::getRandom(  );
        }
    }
    
    double default_getRandom(  ) {
        return StochasticParameter< double >::getRandom( );
    }

    virtual void setToAverage(  ) {
        if( bp::override func_setToAverage = this->get_override( "setToAverage" ) )
            func_setToAverage(  );
        else{
            this->StochasticParameter< double >::setToAverage(  );
        }
    }
    
    void default_setToAverage(  ) {
        StochasticParameter< double >::setToAverage( );
    }

};

void register_StochasticSampledParameter_class(){

    bp::class_< StochasticSampledParameter_wrapper, bp::bases< StochasticParameter< double > >, boost::noncopyable >( "StochasticSampledParameter", bp::init< StochasticParameter< double > const &, size_t, double, double >(( bp::arg("par"), bp::arg("nbins"), bp::arg("xmin"), bp::arg("xmax") )) )    
        .def( bp::init< StochasticParameter< double > const &, size_t, bp::optional< int > >(( bp::arg("par"), bp::arg("nbins"), bp::arg("nfwhm")=(int)(3) )) )    
        .def( 
            "clone"
            , (::StochasticSampledParameter * ( ::StochasticSampledParameter::* )(  ) const)(&::StochasticSampledParameter::clone)
            , (::StochasticSampledParameter * ( StochasticSampledParameter_wrapper::* )(  ) const)(&StochasticSampledParameter_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getBinValue"
            , (double ( ::StochasticSampledParameter::* )( ::size_t ) const)( &::StochasticSampledParameter::getBinValue )
            , ( bp::arg("ibin") ) )    
        .def( 
            "getNbins"
            , (::size_t ( ::StochasticSampledParameter::* )(  ) const)( &::StochasticSampledParameter::getNbins ) )    
        .def( 
            "getNormalizedProbability"
            , (double ( ::StochasticSampledParameter::* )( ::size_t ) const)( &::StochasticSampledParameter::getNormalizedProbability )
            , ( bp::arg("ibin") ) )    
        .def( 
            "probabilityBinDensity"
            , (double ( ::StochasticSampledParameter::* )( ::size_t ) const)( &::StochasticSampledParameter::probabilityBinDensity )
            , ( bp::arg("ibin") ) )    
        .def( 
            "probabilityDensity"
            , (double ( ::StochasticSampledParameter::* )( double ) const)(&::StochasticSampledParameter::probabilityDensity)
            , (double ( StochasticSampledParameter_wrapper::* )( double ) const)(&StochasticSampledParameter_wrapper::default_probabilityDensity)
            , ( bp::arg("value") ) )    
        .def( 
            "setToRandom"
            , (void ( ::StochasticSampledParameter::* )(  ) )(&::StochasticSampledParameter::setToRandom)
            , (void ( StochasticSampledParameter_wrapper::* )(  ) )(&StochasticSampledParameter_wrapper::default_setToRandom) )    
        .def( 
            "getFWHM"
            , (double ( ::StochasticParameter<double>::* )(  ) const)(&::StochasticParameter< double >::getFWHM)
            , (double ( StochasticSampledParameter_wrapper::* )(  ) const)(&StochasticSampledParameter_wrapper::default_getFWHM) )    
        .def( 
            "getRandom"
            , (double ( ::StochasticParameter<double>::* )(  ) )(&::StochasticParameter< double >::getRandom)
            , (double ( StochasticSampledParameter_wrapper::* )(  ) )(&StochasticSampledParameter_wrapper::default_getRandom) )    
        .def( 
            "setToAverage"
            , (void ( ::StochasticParameter<double>::* )(  ) )(&::StochasticParameter< double >::setToAverage)
            , (void ( StochasticSampledParameter_wrapper::* )(  ) )(&StochasticSampledParameter_wrapper::default_setToAverage) );

}