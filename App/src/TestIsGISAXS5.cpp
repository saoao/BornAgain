#include "TestIsGISAXS5.h"

#include "Utils.h"
#include "OutputData.h"
#include "IsGISAXSTools.h"
#include "MultiLayer.h"
#include "Layer.h"
#include "MaterialManager.h"
#include "Particle.h"
#include "ParticleDecoration.h"
#include "FormFactorCylinder.h"
#include "StochasticSampledParameter.h"
#include "ParticleBuilder.h"
#include "LayerDecorator.h"
#include "Units.h"
#include "StochasticGaussian.h"
#include "InterferenceFunctionNone.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "GISASExperiment.h"
#include "DrawHelper.h"
#include "FitSuite.h"
#include "FitSuiteHelper.h"
#include "ResolutionFunction2DSimple.h"
#include "MathFunctions.h"
#include "ROOTMinimizer.h"
#include "OutputDataFunctions.h"
#include "ExperimentConstants.h"
#include "OutputDataIOFactory.h"
#include "IsGISAXSData.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "TCanvas.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLine.h"
#include "TROOT.h"
#include "TLegend.h"


TestIsGISAXS5::TestIsGISAXS5()
    : IFunctionalTest("TestIsGISAXS5")
    , m_experiment(0)
    , m_sample_builder(0)

{
    setOutputPath(Utils::FileSystem::GetHomePath()+"./Examples/IsGISAXS_examples/ex-5/");
}


void TestIsGISAXS5::execute()
{
    // initializing experiment and sample builder
    initialiseExperiment();

    // run our standard isgisaxs comparison
    //run_isgisaxs_comparison();

    // plot IsGISAXS data and IsGISAXS fit results
    //plot_isgisaxs_fit_results();

    // run isgisaxs ex-5 style fit
    run_isgisaxs_fit();
}


/* ************************************************************************* */
// standard ixgisaxs comparison
/* ************************************************************************* */
void TestIsGISAXS5::run_isgisaxs_comparison()
{
    // run simulation for default sample parameters
    m_experiment->runSimulation();
    OutputDataIOFactory::writeOutputData(*(m_experiment->getOutputData()), getOutputPath()+"this_fitexample.ima");

    // plotting results of comparison we/isgisaxs for the sample with default parameters
    std::string isgi_file(getOutputPath()+"isgi_fitexample.ima.gz");
    std::string this_file(getOutputPath()+"this_fitexample.ima");

    // -------------
    // plot results
    // -------------
    OutputData<double> *isgi_data = OutputDataIOFactory::getOutputData(isgi_file);
    OutputData<double> *our_data = OutputDataIOFactory::getOutputData(this_file);

    IsGISAXSTools::drawOutputDataComparisonResults(*our_data, *isgi_data,"TestIsGISAXS5_c1", "ex-5: cylinders with size distribution and 1D paracrystal inderference function");

    delete isgi_data;
    delete our_data;
}


/* ************************************************************************* */
// plot IsGISAXS data (*.dat file) and IsGISAXS fit results (*.out file)
/* ************************************************************************* */
void TestIsGISAXS5::plot_isgisaxs_fit_results()
{
    // reading isgisaxs scans which actually have been used for a fit together with fit results (100 points/scan)
    IsGISAXSData::DataSet_t isgi_scans_smoothed;
    IsGISAXSData::read_outfile(getOutputPath()+"isgi_fitexample.out", isgi_scans_smoothed, IsGISAXSData::kData2fit);
    IsGISAXSData::DataSet_t isgi_results;
    IsGISAXSData::read_outfile(getOutputPath()+"isgi_fitexample.out", isgi_results, IsGISAXSData::kSimResult);

    TCanvas *c1 = DrawHelper::instance().createAndRegisterCanvas("c1_isgisaxs_data", "Looking on IsGISAXS data and fit results", 800, 500);
    c1->Divide(2,2);

    // drawing isgsaxs fit results on top of isgisaxs real data
    TLegend *leg2 = new TLegend(0.5,0.6,0.85,0.85);
    leg2->SetBorderSize(1);
    leg2->SetFillStyle(0);
    for(int i_set=0; i_set<(int)isgi_scans_smoothed.size(); ++i_set) {
        c1->cd(1+i_set); gPad->SetLogy();
        TH1D *hdata = IsGISAXSTools::getOutputDataScanHist(*isgi_results[i_set], "data");
        hdata->SetLineColor(kRed);
        hdata->DrawCopy();
        if(i_set==0) leg2->AddEntry(hdata,"isgisaxs results","lp");
        TH1D *hdata_smoothed = IsGISAXSTools::getOutputDataScanHist(*isgi_scans_smoothed[i_set], "data_smoothed");
        hdata_smoothed->SetLineColor(kBlue);
        hdata_smoothed->DrawCopy("same");
        if(i_set==0) leg2->AddEntry(hdata_smoothed,"isgisaxs data","lp");
    }
    c1->cd(1); leg2->Draw();
    c1->cd(2); leg2->Draw();

    // drawing ratio of isgisaxs data/results
    TLegend *leg3 = new TLegend(0.5,0.6,0.85,0.85);
    leg3->SetBorderSize(1);
    leg3->SetFillStyle(0);
    for(int i_set=0; i_set<(int)isgi_scans_smoothed.size(); ++i_set) {
        c1->cd(3+i_set);
        *isgi_results[i_set] /= *isgi_scans_smoothed[i_set];
        TH1D *hdata = IsGISAXSTools::getOutputDataScanHist(*isgi_results[i_set], "isgisaxs_results_data");
        hdata->SetLineColor(kRed);
        hdata->DrawCopy();
        if(i_set==0) leg3->AddEntry(hdata,"isgisaxs results/data","lp");
    }
    c1->cd(3); leg3->Draw();
    c1->cd(4); leg3->Draw();

    c1->Update();
}


/* ************************************************************************* */
// run isgisaxs ex-12 style fit
/* ************************************************************************* */
void TestIsGISAXS5::run_isgisaxs_fit()
{
    // reading info about two 1D scans defined in isgisaxs example
    IsGISAXSData::DataSet_t isgi_scans;
    //IsGISAXSData::read_outfile(getOutputPath()+"isgi_fitexample.out", isgi_scans, IsGISAXSData::kData2fit);
    IsGISAXSData::read_datfile(getOutputPath()+"isgi_fitexample.dat", isgi_scans);

    // creating fit suite
    m_fitSuite = new FitSuite();
    m_fitSuite->setMinimizer( new ROOTMinimizer("Minuit2", "Migrad") );
    //m_fitSuite->setMinimizer( new ROOTMinimizer("Minuit2", "Fumili") );
    //m_fitSuite->setMinimizer( new ROOTMinimizer("GSLMultiFit", "") );
    //m_fitSuite->setMinimizer( new ROOTMinimizer("Fumili", "") );
    m_fitSuite->attachObserver( new FitSuiteObserverPrint(10) );
    m_fitSuite->attachObserver( new FitSuiteObserverDraw(10) );
//    ROOT::Math::Minimizer *minim = (dynamic_cast<ROOTMinimizer *>(m_fitSuite->getMinimizer()))->getROOTMinimizer();
//    minim->SetPrintLevel(4);
//    minim->SetMaxIterations(400);
//    minim->SetTolerance(0.1);
    //minim->SetPrecision(0.004);
//    minim->SetStrategy(1);
//    minim->SetPrecision(1.);

    m_fitSuite->addFitParameter("*Normalizer/scale", 1e5, 1, AttLimits::limited(1e4, 2e5));
    m_fitSuite->addFitParameter("*Normalizer/shift", 10, 0.01, AttLimits::limited(1., 20.));
    m_fitSuite->addFitParameter("*SampleBuilder/particle_radius",  4*Units::nanometer, 0.01*Units::nanometer, AttLimits::limited(1., 10.) );
    m_fitSuite->addFitParameter("*SampleBuilder/dispersion_radius",  0.2, 0.01, AttLimits::limited(0.01, 1.) );
    m_fitSuite->addFitParameter("*SampleBuilder/height_aspect_ratio",  0.8, 0.01, AttLimits::limited(0.01, 10.) );
    m_fitSuite->addFitParameter("*SampleBuilder/interf_distance",  12*Units::nanometer, 0.01*Units::nanometer, AttLimits::limited(0.01, 50.0) );
    m_fitSuite->addFitParameter("*SampleBuilder/interf_width",  6*Units::nanometer, 0.01*Units::nanometer, AttLimits::limited(0.01, 10.) );

    // setting up fitSuite
    ChiSquaredModule chiModule;
    //chiModule.setChiSquaredFunction( SquaredFunctionWithSystematicError(0.08) );
    chiModule.setChiSquaredFunction(SquaredFunctionDefault());// isgisaxs uses epsion=0, which correspond to our SquaredFunctionDefault
    chiModule.setOutputDataNormalizer( OutputDataNormalizerScaleAndShift() );
    chiModule.setIntensityFunction( IntensityFunctionSqrt() );

    for(IsGISAXSData::DataSet_t::iterator it=isgi_scans.begin(); it!= isgi_scans.end(); ++it) {
        m_fitSuite->addExperimentAndRealData(*m_experiment, *(*it), chiModule);
    }

    m_fitSuite->runFit();

    // drawing results
    TCanvas *c2 = new TCanvas("c2","GISASFW fit results",800,600);
    c2->Divide(2,2);
    TLegend *leg1 = new TLegend(0.5,0.6,0.85,0.85);
    leg1->SetBorderSize(1);
    leg1->SetFillStyle(0);
    for(size_t i_set=0; i_set<m_fitSuite->getFitObjects()->size(); ++i_set) {
        c2->cd((int)i_set+1);
        const FitObject *obj = m_fitSuite->getFitObjects()->getObject(i_set);
        TH1D *hreal = IsGISAXSTools::getOutputDataScanHist(*obj->getChiSquaredModule()->getRealData(),"gisasfw_real");
        TH1D *hsimul = IsGISAXSTools::getOutputDataScanHist(*obj->getChiSquaredModule()->getSimulationData(),"gisasfw_simul");
        hreal->SetLineColor(kBlue);
        gPad->SetLogy();
        hreal->DrawCopy();
        hsimul->DrawCopy("same");
        if(i_set==0) leg1->AddEntry(hreal,"GISASFW data","lp");
        if(i_set==0) leg1->AddEntry(hsimul,"GISASFW simul","lp");
    }
    c2->cd(1); leg1->Draw();
    c2->cd(2); leg1->Draw();

    // drawing ratio
    TLegend *leg2 = new TLegend(0.5,0.6,0.85,0.85);
    leg2->SetBorderSize(1);
    leg2->SetFillStyle(0);
    for(size_t i_set=0; i_set<m_fitSuite->getFitObjects()->size(); ++i_set) {
        c2->cd(3+1);
        const FitObject *obj = m_fitSuite->getFitObjects()->getObject(i_set);
        OutputData<double > *real = obj->getChiSquaredModule()->getRealData()->clone();
        OutputData<double > *simul = obj->getChiSquaredModule()->getSimulationData()->clone();

        c2->cd((int)(i_set+3));
        *simul /= *real;
        TH1D *hratio = IsGISAXSTools::getOutputDataScanHist(*simul,"gisasfw_real_simul_ratio");
        hratio->DrawCopy();
        if(i_set==0) {
            leg2->AddEntry(hratio,"GISASFW simul/real","lp");
        }
        delete real;
        delete simul;
    }
    c2->cd(3); leg2->Draw();
    c2->cd(4); leg2->Draw();

    c2->Update();
}




/* ************************************************************************* */
// initialize experiment
/* ************************************************************************* */
void TestIsGISAXS5::initialiseExperiment()
{
    delete m_sample_builder;
    m_sample_builder = new SampleBuilder();
    delete m_experiment;
    m_experiment = new GISASExperiment(mp_options);
    m_experiment->setSampleBuilder(m_sample_builder);
    m_experiment->setDetectorParameters(100, 0.0*Units::degree, 2.0*Units::degree, 100, 0.0*Units::degree, 2.0*Units::degree, true);
    m_experiment->setBeamParameters(1.0*Units::angstrom, -0.2*Units::degree, 0.0*Units::degree);
}


/* ************************************************************************* */
// IsGISAXS ex-5 sample builder
/* ************************************************************************* */
TestIsGISAXS5::SampleBuilder::SampleBuilder()
    : m_particle_radius(4.0*Units::nanometer)
    , m_dispersion_radius(0.2)
    , m_height_aspect_ratio(0.8)
    , m_interf_distance(12*Units::nanometer)
    , m_interf_width(6.0*Units::nanometer)
{
      init_parameters();
}

void TestIsGISAXS5::SampleBuilder::init_parameters()
{
    getParameterPool()->clear();
    getParameterPool()->registerParameter("particle_radius", &m_particle_radius);
    getParameterPool()->registerParameter("dispersion_radius", &m_dispersion_radius);
    getParameterPool()->registerParameter("height_aspect_ratio", &m_height_aspect_ratio);
    getParameterPool()->registerParameter("interf_distance", &m_interf_distance);
    getParameterPool()->registerParameter("interf_width", &m_interf_width);
}

ISample *TestIsGISAXS5::SampleBuilder::buildSample() const
{
    MultiLayer *p_multi_layer = new MultiLayer();

    complex_t n_particle(1.0-6e-4, 2e-8);
    const IMaterial *air_material = MaterialManager::instance().addHomogeneousMaterial("Air", 1.0, 0.0);
    const IMaterial *substrate_material = MaterialManager::instance().addHomogeneousMaterial("Substrate", 1.0-6e-6, 2e-8);

    Layer air_layer(air_material);
    double height = m_height_aspect_ratio*m_particle_radius;
    FormFactorCylinder *ff_cylinder = new FormFactorCylinder(height, m_particle_radius);
    Particle cylinder(n_particle, ff_cylinder );

    // radius of nanoparticles will be sampled with gaussian probability
    int nbins=20;
    double sigma = m_particle_radius*m_dispersion_radius;
    int nfwhm(2); // to have xmin=average-nfwhm*FWHM, xmax=average+nfwhm*FWHM (nfwhm = xR/2, where xR is what is defined in isgisaxs *.inp file)
    StochasticSampledParameter stochastic_parameter(StochasticDoubleGaussian(m_particle_radius, sigma), nbins, nfwhm);

    ParticleDecoration particle_decoration;
    IInterferenceFunction *p_interference_function = new InterferenceFunction1DParaCrystal(m_interf_distance, m_interf_width, 1e7*Units::nanometer); // peak_distance, width, corr_length
    particle_decoration.addInterferenceFunction(p_interference_function);

    // building nano particles
    ParticleBuilder builder;
    builder.setPrototype(cylinder,"/Particle/FormFactorCylinder/radius", stochastic_parameter);
    builder.plantParticles(particle_decoration);

    // making layer holding all whose nano particles
    LayerDecorator air_layer_decorator(air_layer, particle_decoration);
    p_multi_layer->addLayer(air_layer_decorator);

    Layer substrate_layer;
    substrate_layer.setMaterial(substrate_material);
    p_multi_layer->addLayer(substrate_layer);

    return p_multi_layer;
}
