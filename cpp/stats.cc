#include "readcsv.h"
#include <iostream>
#include <vector>
//#include <map>

void showToyStats(Toybox &toybox){
    std::cout<<"counting toys:"<<std::endl;
    std::vector<int> minutesByDay(2);
    
    int daySize=2;
    int totalDuration = 0;
    for (auto &i : toybox) {
        int day = i->arrivalTime/(1440*60);
        if(day>=daySize){
            daySize=day+1;
            minutesByDay.resize(daySize);
        }
        minutesByDay[day]+=i->duration;
        totalDuration+=i->duration;
    }
    int day=0;
    for (auto i:minutesByDay ) {
        ++day;
        std::cout << day<<","<<(float)i/8.1e5<< std::endl;
    }
    std::cout<< "total duration: "<<totalDuration <<" average: "
        << (float)totalDuration/toybox.size() << std::endl 
        << "size: " << toybox.size() << std::endl;
}

