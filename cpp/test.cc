#include <iostream>
#include <ctime>
//Boost Test Library Unit Test Framework [UTF].
#include <boost/test/included/unit_test.hpp>//static library
//http://www.boost.org/doc/libs/1_44_0/libs/test/doc/html/utf/testing-tools/output-test.html
#include <boost/test/output_test_stream.hpp>
//#include <boost/test/included/prg_exec_monitor.hpp>//static library, calls cpp_main() 
//#include <stdexcept>
extern int strToRel(const char*);
extern void relToStr(int, char*, int);
extern int globalStart(void);

//BOOST_AUTO_TEST_CASE(FUNCTION);
//BOOST_AUTO_TEST_SUITE(SUITE_NAME);
//libunit_test_framework.lib should only be required to be linked 
//if boost/test/unit_test.hpp is the only boost test include file. 
//unit_test_log::instance().set_log_output( std::ostream& );
//BOOST_TEST_LOG_LEVEL env variable

//called from boost test libraries program execution monitor
//int cpp_main(int argc, char *argv[]){

int init_unit_test_suite(int argc, char *argv[]){
    //std::cout<<"running tests. " << std::endl;
    return 0;
}
BOOST_AUTO_TEST_CASE(test){
    char *time;
    time_t _globalStart = (time_t) globalStart();
    //also consider asctime(gmtime());
    time = ctime(&_globalStart);

    boost::test_tools::output_test_stream output;
    output<<time;
    BOOST_CHECK(!output.is_empty(false));
    BOOST_CHECK(output.is_equal("Wed Jan  1 00:00:00 2014\n"));
}   
BOOST_AUTO_TEST_CASE(conversion){
    time_t _globalStart = (time_t) globalStart();
    time_t relTime = strToRel("2014 1 1 0 0");
    time_t sumTime = _globalStart + relTime;
    std::cout << relTime <<", " <<_globalStart << " converts to: " << ctime(&relTime) << std::endl;
    std::cout<<relTime<<std::endl;
    BOOST_CHECK(relTime == 0);
}
