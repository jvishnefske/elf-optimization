#include "main.h" //struct Toy{id,arrivalTime,duration};
//memory,iostream,string
#include <fstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>

#define FILENAME  "../toys_rev2.csv.gz";
vector<unique_ptr<Toy>>& readInput(){
    std::ifstream file(FILENAME,std::ios_base::in|std::ios_base::binary);
    std::filtering_streambuf<std::input> in;
    in.push(zlib_decompressor());
    
    in.push(file);

    //first line of csv is labels
    std::string line;
    in>>line;

    //boost::iostreams::copy(in,std::cout);
    while (in>>line);
}

