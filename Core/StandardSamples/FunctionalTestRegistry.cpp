// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/FunctionalTestRegistry.cpp
//! @brief     Implements class FunctionalTestRegistry.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FunctionalTestRegistry.h"
#include "Exceptions.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

FunctionalTestRegistry::Catalogue FunctionalTestRegistry::m_catalogue = FunctionalTestRegistry::Catalogue();


FunctionalTestRegistry::Catalogue::Catalogue()
{
    add("isgisaxs01",
        "Mixture of cylinders and prisms without interference",
        "isgisaxs01_reference.ima.gz", 2e-10);

    add("isgisaxs02",
        "Mixture cylinder particles with different size distribution",
        "isgisaxs02_reference.ima.gz", 2e-10);

    add("isgisaxs03_ba",
        "Cylinder formfactor in BA",
        "isgisaxs03_reference_BA.ima.gz", 2e-10);
    add("isgisaxs03_dwba",
        "Cylinder formfactor in DWBA",
        "isgisaxs03_reference_DWBA.ima.gz", 2e-10);
    add("isgisaxs03_basize",
        "Cylinder formfactor in BA with size distribution",
        "isgisaxs03_reference_BA_size.ima.gz", 2e-10);

    add("isgisaxs04_1DDL",
        "1D paracrystal",
        "isgisaxs04_reference_1DDL.ima.gz", 2e-10);
    add("isgisaxs04_2DDL",
        "2D paracrystal",
        "isgisaxs04_reference_2DDLh.ima.gz", 2e-10);

    add("isgisaxs06_lattice1",
        "2D lattice with disorders",
        "isgisaxs06_reference_lattice.ima.gz", 2e-10);
    add("isgisaxs06_lattice2",
        "2D lattice centered",
        "isgisaxs06_reference_centered.ima.gz", 2e-10);
    add("isgisaxs06_lattice3",
        "2D lattice rotated",
        "isgisaxs06_reference_rotated.ima.gz", 2e-10);
// this test is complicated for given Registry, see Tests/FunctionalTest/TesCore/IsGISAXS06L4
//    add("isgisaxs06_lattice4",
//        "2D lattice variants",
//        "isgisaxs06_reference_variants.ima.gz", 2e-10);

    add("isgisaxs07",
        "Mixture of different particles a la IsGISAXS morphology file",
        "isgisaxs07_reference.ima.gz", 2e-10);

    add("isgisaxs08a",
        "2DDL paracrystal lattice",
        "isgisaxs08_reference_2DDL_lattice.ima.gz", 2e-10);
    add("isgisaxs08b",
        "2D paracrystal lattice with isotropic pdfs",
        "isgisaxs08_reference_2DDL_lattice2.ima.gz", 2e-10);

    add("isgisaxs09a",
        "Pyramids on top of substrate",
        "isgisaxs09_reference_pyramid_Z0.ima.gz", 2e-10);
    add("isgisaxs09b",
        "Rotated pyramids on top of substrate",
        "isgisaxs09_reference_pyramid_Z45.ima.gz", 2e-10);

    add("isgisaxs10",
        "Cylinders with interference on top of substrate",
        "isgisaxs10_reference.ima.gz", 2e-10);

    add("isgisaxs11",
        "Core shell nanoparticles",
        "isgisaxs11_reference.ima.gz", 2e-10);

    add("isgisaxs15",
        "Size spacing correlation approximation",
        "isgisaxs15_reference.ima.gz", 2e-10);

    add("mesocrystal01",
        "Mesocrystals of cylindrical shape composed by spherical nanoparticles",
        "mesocrystal1_reference_v2_nphi2.txt.gz", 1e-10);

    add("PolarizedDWBAZeroMag",
        "Polarized DWBA with zero magnetic field",
        "isgi_cylinder_DWBA.ima.gz", 1e-10);

    add("LayerWithRoughness",
        "Layers with correlated roughness",
        "layer_with_roughness.ima.gz", 2e-10);

    add("ripple2",
        "Triangular ripple within the 1D-paracrystal model",
        "test_ripple2_sym.ima.gz", 2e-10);

    add("ripple1",
        "Cosine ripple within the 1D-paracrystal model",
        "test_ripple1.ima.gz", 2e-10);

}


void FunctionalTestRegistry::Catalogue::add(const std::string &name,
    const std::string &description, const std::string &reference, double threshold)
{
    catalogue_t::iterator it = m_data.find(name);
    if( it != m_data.end() ) {
        throw ExistingClassRegistrationException("FunctionalTestRegistry::Catalogue::add() -> "
                                                 "Error. Existing item " +name);
    }
    m_data[name] = FunctionalTestInfo(name, description, reference, threshold);
}


void FunctionalTestRegistry::Catalogue::print()
{
    std::cout << "--- FunctionalTestRegistry::Catalogue::print() ---" << std::endl;
    for(catalogue_t::iterator it = m_data.begin(); it!= m_data.end(); ++it) {
        FunctionalTestInfo &info = (*it).second;
//        std::cout << std::setw(21) << std::left << info.m_name << " | "
//                  << std::setw(34) << std::left << info.m_description << " | "
//                  << std::setw(12) << std::left << info.m_reference_file << " | "
//                  << std::setw(6) << std::left  << info.m_threshold << std::endl;
        std::cout << Utils::AdjustStringLength(info.m_name, 20) << " | "
                  << Utils::AdjustStringLength(info.m_description, 40) << " | "
                  << Utils::AdjustStringLength(info.m_reference_file, 40) << " | "
                  << std::setw(6) << std::left  << info.m_threshold << std::endl;




    }
}


FunctionalTestInfo FunctionalTestRegistry::Catalogue::getInfo(const std::string &name)
{
    catalogue_t::iterator it = m_data.find(name);
    if( it == m_data.end() ) {
        std::ostringstream ostr;
        ostr << "FunctionalTestRegistry::Catalogue::getInfo() -> Error. "
             << "Not existing test name '" << name << "'. "
             << "Existing items are:" << std::endl;
        for(catalogue_t::iterator it2 = m_data.begin(); it2!=m_data.end(); ++it2) {
            ostr << (*it2).first << std::endl;
        }
        throw ExistingClassRegistrationException(ostr.str());
    }
    return m_data[name];
}


bool FunctionalTestRegistry::isRegisteredName(const std::string &name)
{
    if( m_catalogue.m_data.find(name) == m_catalogue.m_data.end() ) {
        return false;
    } else {
        return true;
    }
}


FunctionalTest_t FunctionalTestRegistry::getTest(const std::string &name)
{
    FunctionalTest_t test(new FunctionalTest(m_catalogue.getInfo(name)));
    return test;
}


//FunctionalTest_t FunctionalTestRegistry::runTest(const std::string &name)
//{
//    FunctionalTest_t test(new FunctionalTest(m_catalogue.getInfo(name)));
//    test->runTest();
//    return test;
//}


int FUNCTIONAL_TEST(const std::string &name)
{
    FunctionalTestRegistry registry;
    FunctionalTest_t test = registry.getTest(name);
    test->runTest();
    return test->analyseResults();
}


