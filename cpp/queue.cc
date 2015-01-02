//#include <utility> //pair
#include <algorithm>//max, sort,
#include <memory>
#include "main.h"
#include "time.h" //Chronos
#include <cmath> //pow

//#define IS_SANCTIONED_TIME(x) ((x%1440)>=(9*60)&&(x%1440)<(19*60))?true:false


// we could expand this concept to one of a polymorphic heuristic which stores
// an arbitraty object, and comparison function.
// template <class T, class Comparison Functor>
// class HeuristicContainer: std::vector<T 
// allow selecting elves according to a given heuristic.
// the heuristic is provided by a comparison function such as comparing by the duration.
// This allows sorting by the comparison metric, and binary search returning an iterator.
  

//return error status, and possibly updated state.
//std::pair<int,ElfState> 

    bool updateState(const ElfState &priorState,const Toy &toy,ElfState &nextState){
        Chronos &chronos = Chronos::getChronos();
        //const int invalidHoursPerDay = 14;
        //const int validHoursPerDay = 10;
        int startTime = priorState.nextStartTime;
        //int fullDays = DIV_CEIL(toy.duration, priorState.efficiency) / 1440;
        int endTime = startTime + 
            DIV_CEIL(toy.duration, priorState.efficiency);
        //count valid hours, and assume remainint is overTime.
        float sanctionedHours,unsanctionedHours;
        /*if (chronos.isSanctonedTime(endTime)){
            unsanctionedHours = fullDays * insanctionedHoursPerDay * priorState.efficiency  ;
            validHours = toy.duration /60  - overtimeHours;
        }else{
            
            validHours = (float)fullDays * validHoursPerDay* priorState.efficiency +
                (19*60-startTime % 1440)/60.0 * priorState.efficiency; // time in first shift.
            overtimeHours = toy.duration/60. - validHours;
        }*/
        chronos.getSanctionedBreakDown(priorState.nextStartTime, toy.duration, priorState.efficiency,
                                     sanctionedHours, unsanctionedHours);
        nextState.toyId = toy.id;
        
        chronos.nextStartTime(endTime, priorState.efficiency , unsanctionedHours, nextState.nextStartTime );

        nextState.efficiency = priorState.efficiency *
            std::pow(1.02,sanctionedHours) *
            std::pow(0.9,unsanctionedHours);
    
        //enforce efficency envelopes
        if (nextState.efficiency > 4.0){
            nextState.efficiency = 4;
        }else if (nextState.efficiency<.25){
            nextState.efficiency = .25;
        }
        
        
        return true;


/*

        int penalty = DIV_CEIL(unsanctionedHours*60,priorState.efficiency);
        int penaltyDays = penalty / 600;
        int penaltyMinutes = penalty % 600;
        std::cout<<"efficiency "<< priorState.efficiency<<" penalty "<<penaltyMinutes
            <<" overtime: "<<unsanctionedHours<<" days "<<fullDays<<std::endl;
        if (chronos.isSanctonedTime(endTime)){
            nextState.nextStartTime = endTime + penaltyDays * 1440 + penaltyMinutes; 
        } else {
            int tomorrowMorning = ((int)(endTime+14*60)/1440)*1440 + 9*60;
            nextState.nextStartTime = tomorrowMorning + penaltyDays * 1440 + penaltyMinutes; 
        }*/

        
    }
