#include "main.h" //struct Toy{id,arrivalTime,duration};
//memory,iostream,string
#include <fstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <vector>
#include <memory>
#include <ctime>
//#define FILENAME  "../toys_rev2.csv.gz";
#define FILENAME "./toys.csv"
/* std::vector<std::unique_ptr<Toy>>& readInput(){
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
*/
const char* timeFormat = "%Y %m %d %H %m";
inline time_t globalStart(){
    static struct std::tm tm_globalStart ; 
        strptime("2014 1 1 0 0",timeFormat,&tm_globalStart);
    static time_t t_globalStart =  mktime(&tm_globalStart);
    return t_globalStart;
}
int strToRel(const char* sdate){
   struct std::tm tm_date;
    strptime(sdate,timeFormat,&tm_date);
    time_t date = mktime(&tm_date);    
    int time = difftime(date,globalStart());
    return time;
}
void relToStr(int relTime,char *out,int maxLen){
    
    time_t gStart = globalStart();
    time_t time = gStart+(time_t)relTime;
    struct std::tm tm_time;
    gmtime_r(&time,&tm_time);
    strftime(out,maxLen,timeFormat,&tm_time);    
}

