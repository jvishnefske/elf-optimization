//#include <utility> //pair
#include <algorithm>//max, sort,
#include <memory>
#include "main.h"

#define minuteIsNormal(x) ((x%1440)>=(9*60)&&(x%1440)<=(19*60))?true:false
#define DIV_CEIL(x,y) (int)((x/(float)(y))  -.00001 )+1
/* defined in main.h:
struct ElfState {
    public:
        ElfState(int _elfId):elfId(_elfId), efficiency(1),lastCompleted(0),nextStartTime(0){}
    int elfId;
    float efficiency;
    int lastCompleted; //toyid
    // the time the next task may consider.
    int nextStartTime; 
};*/
// we could expand this concept to one of a polymorphic heuristic which stores
// an arbitraty object, and comparison function.
/*template <class T, class Comparison Functor>
class HeuristicContainer: std::vector<T 
   //allow selecting elves according to a given heuristic.
    // the heuristic is provided by a comparison function such as comparing by the duration.
    // This allows sorting by the comparison metric, and binary search returnign an iterator.
    private:
        std::vector<Elf> heuristic

    public:
}*/

//return error status, and possibly updated state.
//std::pair<int,ElfState> 
bool updateState(const ElfState &priorState,Toy &toy,ElfState &nextState){
    int newStartTime = priorState.nextStartTime;
    int validMinCount=0;
    int invalidMinCount=0;
    float efficiency=priorState.efficiency;
    int endTime = newStartTime+efficiency*toy.duration;
    //durration counts from length to 0, 
    //marker tracks the current real time in minutes, we have counted to.
    float durrationCountDown = toy.duration;
    int minuteMarker = newStartTime;
    while(durrationCountDown>0){
         if (minuteIsNormal(minuteMarker)){
            //minutes to end of workday times effeciency
            int minutesToEndOfWorkday=(1900*60-(minuteMarker%1440));
            if(durrationCountDown>minutesToEndOfWorkday*efficiency){
                //we round down when converting from realtime to job minutes
                int workdayTaskTime=minutesToEndOfWorkday*efficiency; 
                validMinCount += workdayTaskTime;
                durrationCountDown -= workdayTaskTime;
            
            }else{
                //this is the last section of durrationCountDown
                //remember to divide and round up
                //since the integer division operation typically returns both 
                //  ceil(x/y)=(x+y-1)/y
                int dayMinutes = ((int)durrationCountDown/priorState.efficiency)+DurrationCounter;
            }
         }else{
            int minutesToStartOfWorkday=(9*60-minuteMarker)%1440;
            if (durrationCountDown>DurrationCounter){
            
            }
            invalidMinCount+=minutesToStartOfWorkday;

         }
    }
    if (toy.arrivalTime > newStartTime) 
        newStartTime = toy.arrivalTime;
    if (!timeIsNormal(priorState.lastCompleted)){
        int Penalty=
    }
    //we need to check if the startTime is within allowed hours.
    //also possibly check if it would be more efficient to start the task next morning
    //and leave a small gap at the end of a day.
    
    int DurrationCounter=
    efficencyCoeficient = 1.0
   return std::pair<int,ElfState>(true,newState);
}
