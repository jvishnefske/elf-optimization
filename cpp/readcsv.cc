#include "readcsv.h"
#include "time.h" //Chronos
#include "main.h" //struct Toy

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <utility> //move
//#include <iomanip> //get_time
//#include <locale> //time_get
//#include <ctime> //attempt to speed up time parsing.

std::vector<std::unique_ptr<Toy> > readToys(std::istream &file)
{
    Chronos & chronos = Chronos::getChronos();
    //std::wcslen
    std::string line;
    std::string token;
    std::vector<std::unique_ptr<Toy> > toybox;
    std::getline(file,line); //read header;
    //std::tm tempTm;
    //time_t tempTime;
    //auto timeFormat = "%Y %m %d %H %M";
    //std::get_time is not implemented in deployed libc++ version
    //stream >> std::get_time(&tempTm,timeFormat);
    //tempTime = mktime(&tempTm);
    std::istringstream stream(line,std::ios_base::in);
    while(std::getline(file,line)) {
        
        auto toy=std::unique_ptr<Toy>(new Toy());
        stream.str(line);
        
        stream >> toy->id;
        std::getline(stream,token,',');
        std::getline(stream,token,',');

        toy->arrivalTime = chronos.convertToMinutes(token);
        stream >> toy->duration;

        toybox.push_back(std::move(toy));
        
               
    }    
    //std::cout << "The last time in the input stream is "<<std::asctime(&tempTm)<<" abs of "<< tempTime <<std::endl;
    return toybox;
}

std::vector<std::unique_ptr<Toy> > readToys(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    return readToys((std::istream&)file);
}

//std::vector<std::unique_ptr<Toy> > readToys(){
//    return readToys("~/src/kaggle/elves/toys_rev2.csv");
//}

std::vector<std::unique_ptr<Toy> > readcsvz(std::string filename)
{
    //open comperssed file, pass the 
    std::ifstream file; 
    file.open(filename);
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(file);
    //std::ofstream devnull{"/dev/null",std::ios::out||std::ios::binary};
    std::istream instream{&in};
    //boost:iostreams::copy()
    return readToys( instream);
    
}
