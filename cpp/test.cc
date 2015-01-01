
#include <iostream>
#include <ctime>
#include "main.h"
#include "queue.h"
#include "time.h"
#define  BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Elf
//Boost Test Library Unit Test Framework [UTF].
//#include <boost/test/included/unit_test.hpp>//static library is slow to compile
//http://www.boost.org/doc/libs/1_44_0/libs/test/doc/html/utf/testing-tools/output-test.html
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

/**
 * @brief main unit testfunction.
 * @details runs before the auto unit tests
 * 
 * @param argc argument count
 * @param argv Command line arguments
 * 
 * @return shell returnvalue.
 */
int init_unit_test_suite(int argc, char *argv[]){
    //std::cout<<"running tests. " << std::endl;
    if(false){std::cout<<argv[argc-1];}

    return 0;
}

//BOOST_AUTO_TEST_CASE(test_name)
BOOST_AUTO_TEST_CASE(globalStartTime){
    Chronos &chronos = Chronos::getChronos();
    char *time;
    const time_t _globalStart = (time_t) chronos.getGlobalStart();
    //also consider asctime(gmtime());

    time = ctime(&_globalStart);

    BOOST_CHECK_EQUAL(_globalStart, 1388563200);
    boost::test_tools::output_test_stream output;
    output<<time;
    BOOST_CHECK(!output.is_empty(false));
    BOOST_CHECK(output.is_equal("Wed Jan  1 00:00:00 2014\n"));
}   
BOOST_AUTO_TEST_CASE(conversion){
    Chronos &chronos = Chronos::getChronos();
    time_t _globalStart = (time_t) chronos.getGlobalStart();
    time_t relTime = chronos.convertToMinutes("2014 1 1 0 0");
    time_t sumTime = _globalStart + relTime;
    //std::cout << relTime <<", " <<_globalStart << " converts to: " << ctime(&relTime) << std::endl;
    //std::cout<<relTime<<std::endl;
    BOOST_CHECK_EQUAL(relTime, 0);
    BOOST_CHECK_EQUAL(sumTime, 1388563200);
}

BOOST_AUTO_TEST_CASE(conversion_to_string){
    Chronos &chronos = Chronos::getChronos();
    int relTime = chronos.convertToMinutes("2014 1 1 0 0");
    //char stime[255];
    //relToStr(relTime*60,stime,254);
    std::string stime = 
        chronos.toString(relTime);
    chronos.toString(relTime);
    
    boost::test_tools::output_test_stream output;
    output << stime;
    BOOST_CHECK(output.is_equal("2014 1 1 0 0"));
}
BOOST_AUTO_TEST_CASE(update_state){

    ElfState state1(0), state2(0);
    Toy toy;
    state1.efficiency = 2;
    state1.nextStartTime = 9*60; // 0900 on first day.
    toy.duration = 120;
    updateState(state1,toy,state2);
    BOOST_CHECK_CLOSE(state2.efficiency,2.0808,.00001);
    BOOST_CHECK_EQUAL(state2.nextStartTime, 10*60);

    state1.efficiency = .5;
    state1.nextStartTime = 19*60-1; //18:59 day 1
    toy.duration = 60*4;
    updateState(state1,toy,state2);
    BOOST_CHECK_CLOSE(state2.efficiency, 0.32805, .00001); // .5 * .9**4
    BOOST_CHECK_EQUAL(state2.nextStartTime, 2460);  // 8 hours penalty on day2


    //multiday durration toy
    state1.efficiency = 4;
    state1.nextStartTime =  1981; //9:01 day 2
    toy.duration = 1440*8;
    updateState(state1,toy,state2);
    //next efficency = 4*.9**(14*2)*1.02**(20.)
    BOOST_CHECK_CLOSE(state2.efficiency, 0.3110668209953771, .00001); 
    BOOST_CHECK_EQUAL(state2.nextStartTime, 4861);  // 8 hours penalty on day2

}