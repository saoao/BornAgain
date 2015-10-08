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
#include "PythonFitList.h"
#include "FitSuite.pypp.h"

namespace bp = boost::python;

struct FitSuite_wrapper : FitSuite, bp::wrapper< FitSuite > {

    FitSuite_wrapper( )
    : FitSuite( )
      , bp::wrapper< FitSuite >(){
        // null constructor
    
    }

    virtual void attachObserver( ::boost::shared_ptr< IObserver > obj ) {
        if( bp::override func_attachObserver = this->get_override( "attachObserver" ) )
            func_attachObserver( obj );
        else{
            this->IObservable::attachObserver( obj );
        }
    }
    
    void default_attachObserver( ::boost::shared_ptr< IObserver > obj ) {
        IObservable::attachObserver( obj );
    }

    virtual void notifyObservers(  ) {
        if( bp::override func_notifyObservers = this->get_override( "notifyObservers" ) )
            func_notifyObservers(  );
        else{
            this->IObservable::notifyObservers(  );
        }
    }
    
    void default_notifyObservers(  ) {
        IObservable::notifyObservers( );
    }

};

void register_FitSuite_class(){

    { //::FitSuite
        typedef bp::class_< FitSuite_wrapper, bp::bases< IObservable >, boost::noncopyable > FitSuite_exposer_t;
        FitSuite_exposer_t FitSuite_exposer = FitSuite_exposer_t( "FitSuite", "Main class to setup and run GISAS fitting in BornAgain.", bp::no_init );
        bp::scope FitSuite_scope( FitSuite_exposer );
        FitSuite_exposer.def( bp::init< >() );
        { //::FitSuite::addFitParameter
        
            typedef void ( ::FitSuite::*addFitParameter_function_type)( ::std::string const &,double,::AttLimits const &,double ) ;
            
            FitSuite_exposer.def( 
                "addFitParameter"
                , addFitParameter_function_type( &::FitSuite::addFitParameter )
                , ( bp::arg("name"), bp::arg("value"), bp::arg("attlim")=AttLimits::limitless( ), bp::arg("step")=0.0 )
                , "Adds fit parameter @param name The name of fit parameter @param value Parameter's starting value @param attlim Limits attribute @param step Initial parameter's step (some minimizers don't use it) \n\n:Parameters:\n  - 'name' - The name of fit parameter\n  - 'value' - Parameter's starting value\n  - 'attlim' - Limits attribute\n  - 'step' - Initial parameter's step (some minimizers don't use it)\n" );
        
        }
        { //::FitSuite::addSimulationAndRealData
        
            typedef void ( ::FitSuite::*addSimulationAndRealData_function_type)( ::GISASSimulation const &,::OutputData< double > const & ) ;
            
            FitSuite_exposer.def( 
                "addSimulationAndRealData"
                , addSimulationAndRealData_function_type( &::FitSuite::addSimulationAndRealData )
                , ( bp::arg("simulation"), bp::arg("real_data") )
                , "Assigns pair of (simulation, real data) for fitting. More than one pair can be added." );
        
        }
        { //::FitSuite::addSimulationAndRealData
        
            typedef void ( ::FitSuite::*addSimulationAndRealData_function_type)( ::GISASSimulation const &,::IHistogram const & ) ;
            
            FitSuite_exposer.def( 
                "addSimulationAndRealData"
                , addSimulationAndRealData_function_type( &::FitSuite::addSimulationAndRealData )
                , ( bp::arg("simulation"), bp::arg("real_data") )
                , "Assigns pair of (simulation, real data) for fitting. More than one pair can be added." );
        
        }
        { //::FitSuite::fixAllParameters
        
            typedef void ( ::FitSuite::*fixAllParameters_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "fixAllParameters"
                , fixAllParameters_function_type( &::FitSuite::fixAllParameters )
                , "Set all parameters to fixed." );
        
        }
        { //::FitSuite::getChi2
        
            typedef double ( ::FitSuite::*getChi2_function_type)(  ) const;
            
            FitSuite_exposer.def( 
                "getChi2"
                , getChi2_function_type( &::FitSuite::getChi2 )
                , "Returns minimum chi squared value found." );
        
        }
        { //::FitSuite::getChiSquaredMap
        
            typedef ::IHistogram * ( ::FitSuite::*getChiSquaredMap_function_type)( ::std::size_t ) const;
            
            FitSuite_exposer.def( 
                "getChiSquaredMap"
                , getChiSquaredMap_function_type( &::FitSuite::getChiSquaredMap )
                , ( bp::arg("i_item")=(::std::size_t)(0) )
                , bp::return_value_policy< bp::manage_new_object >()
                , "returns chi2 histogram calculated for (real, simulated) data pair @param i_item The index of fit object \n\n:Parameters:\n  - 'i_item' - The index of fit object\n" );
        
        }
        { //::FitSuite::getFitObjects
        
            typedef ::FitSuiteObjects * ( ::FitSuite::*getFitObjects_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "getFitObjects"
                , getFitObjects_function_type( &::FitSuite::getFitObjects )
                , bp::return_internal_reference< >()
                , "returns FitObject (pair of simulation/real data)." );
        
        }
        { //::FitSuite::getFitParameters
        
            typedef ::FitSuiteParameters * ( ::FitSuite::*getFitParameters_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "getFitParameters"
                , getFitParameters_function_type( &::FitSuite::getFitParameters )
                , bp::return_internal_reference< >()
                , "Returns reference to fit parameters." );
        
        }
        { //::FitSuite::getFitStrategies
        
            typedef ::FitSuiteStrategies * ( ::FitSuite::*getFitStrategies_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "getFitStrategies"
                , getFitStrategies_function_type( &::FitSuite::getFitStrategies )
                , bp::return_internal_reference< >()
                , "Returns reference to fit parameters." );
        
        }
        { //::FitSuite::getMinimizer
        
            typedef ::IMinimizer * ( ::FitSuite::*getMinimizer_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "getMinimizer"
                , getMinimizer_function_type( &::FitSuite::getMinimizer )
                , bp::return_internal_reference< >()
                , "Returns minimizer." );
        
        }
        { //::FitSuite::getNCalls
        
            typedef ::std::size_t ( ::FitSuite::*getNCalls_function_type)(  ) const;
            
            FitSuite_exposer.def( 
                "getNCalls"
                , getNCalls_function_type( &::FitSuite::getNCalls )
                , "Returns current number of minimization function calls." );
        
        }
        { //::FitSuite::getNStrategy
        
            typedef ::std::size_t ( ::FitSuite::*getNStrategy_function_type)(  ) const;
            
            FitSuite_exposer.def( 
                "getNStrategy"
                , getNStrategy_function_type( &::FitSuite::getNStrategy )
                , "Returns the number of current strategy." );
        
        }
        { //::FitSuite::getRealData
        
            typedef ::IHistogram * ( ::FitSuite::*getRealData_function_type)( ::std::size_t ) const;
            
            FitSuite_exposer.def( 
                "getRealData"
                , getRealData_function_type( &::FitSuite::getRealData )
                , ( bp::arg("i_item")=(::std::size_t)(0) )
                , bp::return_value_policy< bp::manage_new_object >()
                , "returns real data histogram @param i_item The index of fit object \n\n:Parameters:\n  - 'i_item' - The index of fit object\n" );
        
        }
        { //::FitSuite::getSimulationData
        
            typedef ::IHistogram * ( ::FitSuite::*getSimulationData_function_type)( ::std::size_t ) const;
            
            FitSuite_exposer.def( 
                "getSimulationData"
                , getSimulationData_function_type( &::FitSuite::getSimulationData )
                , ( bp::arg("i_item")=(::std::size_t)(0) )
                , bp::return_value_policy< bp::manage_new_object >()
                , "returns simulated data  histogram @param i_item The index of fit object \n\n:Parameters:\n  - 'i_item' - The index of fit object\n" );
        
        }
        { //::FitSuite::initPrint
        
            typedef void ( ::FitSuite::*initPrint_function_type)( int ) ;
            
            FitSuite_exposer.def( 
                "initPrint"
                , initPrint_function_type( &::FitSuite::initPrint )
                , ( bp::arg("print_every_nth") )
                , "Initializes printing to standard output during the fitting. Prints also the summary when completed. @param print_every_nth Print every n'th iteration \n\n:Parameters:\n  - 'print_every_nth' - Print every n'th iteration\n" );
        
        }
        { //::FitSuite::isLastIteration
        
            typedef bool ( ::FitSuite::*isLastIteration_function_type)(  ) const;
            
            FitSuite_exposer.def( 
                "isLastIteration"
                , isLastIteration_function_type( &::FitSuite::isLastIteration )
                , "if the last iteration is done (used by observers to print summary)." );
        
        }
        { //::FitSuite::printResults
        
            typedef void ( ::FitSuite::*printResults_function_type)(  ) const;
            
            FitSuite_exposer.def( 
                "printResults"
                , printResults_function_type( &::FitSuite::printResults )
                , "Returns the number of current strategy." );
        
        }
        { //::FitSuite::releaseAllParameters
        
            typedef void ( ::FitSuite::*releaseAllParameters_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "releaseAllParameters"
                , releaseAllParameters_function_type( &::FitSuite::releaseAllParameters )
                , "Set all parameters to released." );
        
        }
        { //::FitSuite::runFit
        
            typedef void ( ::FitSuite::*runFit_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "runFit"
                , runFit_function_type( &::FitSuite::runFit )
                , "main method to run the fitting." );
        
        }
        { //::FitSuite::setMinimizer
        
            typedef void ( ::FitSuite::*setMinimizer_function_type)( ::std::string const &,::std::string const &,::std::string const & ) ;
            
            FitSuite_exposer.def( 
                "setMinimizer"
                , setMinimizer_function_type( &::FitSuite::setMinimizer )
                , ( bp::arg("minimizer_name"), bp::arg("algorithm_name")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("minimizer_options")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() )
                , "Sets minimizer with given name and algorithm type @param minimizer The name of the minimizer @param algorithm Optional name of the minimizer's algorithm @param options Optional string with additional minimizer settings \n\n:Parameters:\n  - 'minimizer' - The name of the minimizer\n  - 'algorithm' - Optional name of the minimizer's algorithm\n  - 'options' - Optional string with additional minimizer settings\n" );
        
        }
        { //::FitSuite::setParametersFixed
        
            typedef void ( ::FitSuite::*setParametersFixed_function_type)( ::std::vector< std::string > const &,bool ) ;
            
            FitSuite_exposer.def( 
                "setParametersFixed"
                , setParametersFixed_function_type( &::FitSuite::setParametersFixed )
                , ( bp::arg("pars"), bp::arg("is_fixed") )
                , "Set fixed flag for parameters from the list." );
        
        }
        { //::IObservable::attachObserver
        
            typedef void ( ::IObservable::*attachObserver_function_type)( ::boost::shared_ptr< IObserver > ) ;
            typedef void ( FitSuite_wrapper::*default_attachObserver_function_type)( ::boost::shared_ptr< IObserver > ) ;
            
            FitSuite_exposer.def( 
                "attachObserver"
                , attachObserver_function_type(&::IObservable::attachObserver)
                , default_attachObserver_function_type(&FitSuite_wrapper::default_attachObserver)
                , ( bp::arg("obj") ) );
        
        }
        { //::IObservable::notifyObservers
        
            typedef void ( ::IObservable::*notifyObservers_function_type)(  ) ;
            typedef void ( FitSuite_wrapper::*default_notifyObservers_function_type)(  ) ;
            
            FitSuite_exposer.def( 
                "notifyObservers"
                , notifyObservers_function_type(&::IObservable::notifyObservers)
                , default_notifyObservers_function_type(&FitSuite_wrapper::default_notifyObservers) );
        
        }
    }

}
