#ifndef TESTFUNCTIONALTESTS_H
#define TESTFUNCTIONALTESTS_H


#include "IApplicationTest.h"
#include "FunctionalTestRegistry.h"
#include <string>
#include <vector>

//! Plot results of given functional test

class TestFunctionalTests : public IApplicationTest
{
public:
    TestFunctionalTests() {}
    virtual ~TestFunctionalTests() {}

    virtual void execute();

private:
    //! read names of functional tests from command line and check if they are Ok
    bool readTestNames();

    FunctionalTestRegistry m_testRegistry;
    std::vector<std::string> m_testNames;
};


#endif // TESTFUNCTIONALTESTS_H

