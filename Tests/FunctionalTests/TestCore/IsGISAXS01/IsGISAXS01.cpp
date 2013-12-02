#include "IsGISAXS01.h"
#include "OutputDataIOFactory.h"
#include "SampleBuilderFactory.h"
#include "Simulation.h"
#include "Utils.h"
#include "Units.h"
#include "MathFunctions.h"
#include "SimulationRegistry.h"
#include <iostream>
#include <cmath>


FunctionalTests::IsGISAXS01::IsGISAXS01()
    : m_name("IsGISAXS01")
    , m_description("Mixture of cylinders and prisms without interference")
    , m_result(0)
	, m_reference(0)
{ }


void FunctionalTests::IsGISAXS01::run(const std::string &path_to_data)
{

    SimulationRegistry sim_registry;
    Simulation *simulation = sim_registry.createSimulation("isgisaxs01");

    // loading reference data
    std::string filename = path_to_data + "isgisaxs01_reference.ima.gz";
    m_reference = OutputDataIOFactory::readIntensityData(filename);

    simulation->runSimulation();

    m_result = simulation->getIntensityData();
    delete simulation;
}


int FunctionalTests::IsGISAXS01::analyseResults()
{
    const double threshold(2e-10);

    // Calculating average relative difference.
    *m_result -= *m_reference;
    *m_result /= *m_reference;

    double diff(0);
    for(OutputData<double>::const_iterator it =
            m_result->begin(); it!=m_result->end(); ++it) {
        diff+= std::fabs(*it);
    }
    diff /= m_result->getAllocatedSize();

    // Assess result.
	bool status_ok(true);
    if( diff > threshold || std::isnan(diff)) status_ok=false;

    std::cout << " diff " << diff << std::endl;
    std::cout << m_name << " " << m_description << " " <<
            (status_ok ? "[OK]" : "[FAILED]") << std::endl;
    return (status_ok ? 0 : 1);
}


#ifdef STANDALONE
std::string GetPathToData(int argc, char **argv)
{
    if(argc == 2) return argv[1];
    return Utils::FileSystem::GetPathToData("../../../ReferenceData/BornAgain/", argv[0]);
}

int main(int argc, char **argv)
{
    FunctionalTests::IsGISAXS01 test;
    test.run(GetPathToData(argc, argv));
    return test.analyseResults();
}
#endif
