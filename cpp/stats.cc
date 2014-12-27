#include "readcsv.h"
#include <iostream>
#include <vector>
void showToyStats(Toybox &toybox){
    std::cout<<"counting toys:"<<std::endl;
    int totalDuration = 0;
    for (auto &i : toybox) {
        totalDuration+=i->duration;
    }
    std::cout<< "total duration: "<<totalDuration <<" average: "
        << totalDuration/toybox.size() << std::endl 
        << "size: " << toybox.size() << std::endl;
}

