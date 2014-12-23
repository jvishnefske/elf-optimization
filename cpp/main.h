#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
//#include <zlib.h>
time_t strToRel(const char*);
char *relToStr(int,char*,int);
struct Toy{
    int id;
    int arrivalTime;
    int duration;
    //std::unique_ptr<std::string> toString(){
    std::string toString(){
        std::ostringstream oss;
            oss<<"{id:\"" << id <<
            "\",arrivalTime:\"" << arrivalTime <<
            "\"duration:\"" << duration <<"\"}";
        //return unique_ptr<std::string>(oss.str());
        return oss.str();
    }
};
