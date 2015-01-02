#ifndef MAIN_H
#define MAIN_H

#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>




struct Toy{
    Toy(){}
    Toy(int _id,int _time, int _duration):id(_id),arrivalTime(_time),duration(_duration){}
    int id;
    int arrivalTime;
    int duration;
    //std::unique_ptr<std::string> toString()
    std::string toString(){
        std::ostringstream oss;
            oss<<"{id:\"" << id <<
            "\",arrivalTime:\"" << arrivalTime <<
            "\"duration:\"" << duration <<"\"}";
        //return unique_ptr<std::string>(oss.str());
        return oss.str();
    }
};
typedef std::vector<std::unique_ptr<Toy> > Toybox;
void showToyStats(Toybox&);


struct ElfState{

        public:
        ElfState(int _toyId):toyId(_toyId), efficiency(1){}
    //int elfId;
    int toyId;
    float efficiency;

    // the time the next task may consider.
    int nextStartTime; 

    
    int nextTime;

};
struct Elf{
  private:
    int _gaps;
  public:
    Elf(int _elfId):elfId(_elfId){}
    int elfId;
    // private mutable details are stored inside the elfstate.
    std::vector<std::unique_ptr<ElfState> > ElfState;
    bool addToy();
    int gaps(){return _gaps;}

};
#endif //MAIN_H