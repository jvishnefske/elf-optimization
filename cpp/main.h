#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

//#include <zlib.h>
#ifndef MAIN_H
#define MAIN_H
time_t strToRel(const char*);
char *relToStr(int,char*,int);
struct Toy{
    Toy(){}
    Toy(int _id,int _time, int _duration):id(_id),arrivalTime(_time),duration(_duration){}
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
    }};
typedef std::vector<std::unique_ptr<Toy> > Toybox;
void showToyStats(Toybox&);
#endif //MAIN_H
