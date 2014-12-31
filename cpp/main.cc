#include <iostream>
#include "main.h"
#include <getopt.h>
#include <vector>
#include "readcsv.h"
#include <string>

//  #include <boost/lockfree/queue.hpp>
// #include <boost/lockfree/stack.hpp>
// #include <boost/lockfree/spsc_queue.hpp>//ringbuffer
//main.cc



int main(int argc, char *argv[])
{
    // boost::thread_group tgroup;
    // tgroup.create_thread(function);
    // boost::this_thread::sleep(delay);
    // tgroup.create_thread(boost::bind(&isingetr::perform, &teaponSinger))
    // tgroup.join_all();
    // boost::bind(f,_1,_2)(x,y);
    
    //for another example of getopt int cpp see:
    // http://www.chemie.fu-berlin.de/chemnet/use/info/libgpp/libgpp_39.html
    //std::string inputFile = "../toys_rev2.csv";
    //100k subset for faster testing
    std::string inputFile = "toys.csv";
    //check for input file argument
    if (argc==2){
        inputFile = std::string(argv[1]);
    }else{
        std::cout << "no input file argument given, using default,"<<std::endl;
    }


      //if filename ends in z, assume it is gzip.
    Toybox toybox;
    std::cout << "reading input file: "<<inputFile<<std::endl;
    if(inputFile[inputFile.length()-1]=='z'){
        
        toybox = readcsvz(inputFile);
    }else{
        toybox = readToys(inputFile);        
    }
    showToyStats(toybox);

}
