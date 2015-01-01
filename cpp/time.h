
#ifndef TIME_H
#define TIME_H
#define DIV_CEIL(x,y) (int)(((x+y)/(float)(y))  -.0000001 )
#include <ctime>
#include <string>
#include <cassert>

class Chronos 
{
  // we create this as a singleton class since some of the elements
  // are created with the
 private:
   //static Chronos *chronos;
  Chronos() {
    static struct std::tm tm_globalStart;
    strptime("2014 1 1 0 0", timeFormat, &tm_globalStart);
    globalStart = mktime(&tm_globalStart);
  }
  Chronos(Chronos const&);
  void operator=(Chronos const&);

  const char *timeFormat = "%Y %-m %-d %-H %-M";
  const int hoursPerDay = 10;
  const int minutesPerWorkday = hoursPerDay * 60;
  const int unsanctionedHoursPerDay = 14;
  const int dayStart = 9 * 60;
  const int dayEnd = 19 * 60;
  const int minutesIn24h = 1440;
  time_t globalStart; 
 public:
 	time_t getGlobalStart()
 		{return globalStart;}
  static Chronos &getChronos(){
  	static Chronos instance;
    return instance;
  }
  int convertToMinutes(const std::string &date) {
    /** Input: time format
     * output: 
     */
    
    // strptime returns invalid  time_t when struct tm not static.
    static struct std::tm tm_date;
    strptime(date.c_str(), timeFormat, &tm_date);
    time_t t_date = mktime(&tm_date);

    double myTime = difftime(t_date, globalStart);
    return (int) myTime/60;

  }

   std::string toString(int minutes) {
    char tempChar[128];
    size_t maxLen = 127;
    //int relTime = minutes*60;
    
    time_t time = globalStart + (time_t) minutes*60;
    struct std::tm tm_time;
    localtime_r(&time, &tm_time);
  
    strftime(tempChar, maxLen, timeFormat, &tm_time);
    
    return std::string(tempChar);
  }

  bool inline isSanctonedTime(int minute) {
 
  	int dayTime = minute %minutesIn24h;
    return (dayTime >= dayStart && dayTime < dayEnd) ? true: false;
  }
/**
 * @brief maps toy duration to unsanctioned, and sanctioned blocks
 * @details take out whole days (24-hour periods contribute fixed )
 * 			then use basic substution to calculate remaining time.
 * @param minute elapsed minutes since globalStartTime
 * @param  sanctionedHours in terms of toy durration.
 * @param  unsanctionedHours also in terms of toy durration.
 */
  void getSanctionedBreakDown(
  		int startMinute,
   		int toyDuration,
   		float efficency,
   		float &sanctionedHours,
   		float &unsanctionedHours) // in toy duration
  {
  	int minutes = DIV_CEIL(toyDuration,efficency);
  	int endMinute = startMinute + minutes;
	int fullDays = minutes / minutesIn24h;
	if (!isSanctonedTime(startMinute))
		std::cout<< "the offending time is: "<<startMinute<<std::endl;
	assert(isSanctonedTime(startMinute));
	if(isSanctonedTime(endMinute-1)){ //inclusive
		//the only unsanctioned time is full days.
		//since we toyDurration=sanctioned+unsanctioned we can solve.
		unsanctionedHours = fullDays * unsanctionedHoursPerDay * efficency * hoursPerDay;
		sanctionedHours = toyDuration / 60-unsanctionedHours;
	}else{
		const int endOfDayMinute = 19*60;
		sanctionedHours = fullDays * hoursPerDay + 
		(endOfDayMinute-startMinute)/60*efficency;
		unsanctionedHours = toyDuration / 60 -sanctionedHours;
	}
  }
  /**
   * @brief next sanctioned minute including penalty
   * @details takes a minute, and returns the next time which is within 
   * 	a 9:00-19:00 window.
   */
  int nextSanctionedTime(int minute){
  	int sanctionedStart;
  	if(isSanctonedTime(minute)){
  		return minute;
  	}else{
  		const int day=(minute+14*60)/minutesIn24h;
  		sanctionedStart = day * minutesIn24h + dayStart;
  	}
  	return sanctionedStart;
  }
  int nextStartTime(
  		int startMinute,
  		float efficency,
  		float unsanctionedHours,
  		int &nextStartTime)
  {
  	//penalty is only added to sanctioned hours
  	
  	//now calculate penalty, and add.
  	nextStartTime = nextSanctionedTime(startMinute);
  	int penalty = DIV_CEIL(unsanctionedHours*60, efficency);
  	int penaltyMinutes = penalty % minutesPerWorkday;
  	int penaltyDays = penalty / minutesPerWorkday;
  	nextStartTime += penaltyDays * minutesIn24h + penaltyMinutes;
  	return nextStartTime;
  }
};
#endif // TIME_H

