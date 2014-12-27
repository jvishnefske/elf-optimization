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
#include "time.h" //strToRel, relToStr
#include "main.h" //struct Toy
#include "readcsv.h"
//#include <iomanip> //get_time
//#include <locale> //time_get
//#include <ctime> //attempt to speed up time parsing.

//std::vector<std::unique_ptr<Toy> > readcsvz(std::string );
//std::vector<std::unique_ptr<Toy> > readToys(std::string);


int main(int argc, char *argv[])
{
    //auto toybox = readToys("../toys.csv");
    auto toybox = readToys("../../toys_rev2.csv");
    //auto toybox = readcsvz("../../toys_rev2.csv.gz");
    //for (auto &toy : toybox){}
        //std::cout << "id: "<< toy->id 
        //        << "date: "<< toy->arrivalTime 
        //    << "duration: " << toy->duration << ","<<std::endl
        //;
        

        std::cout << "Total of " << toybox.size()  << " toys." << std::endl;
    return 0;
    if (false){
        std::cout <<argv[argc-1];
    }
}


std::vector<std::unique_ptr<Toy> > readToys(std::istream &file)
{
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

        toy->arrivalTime = strToRel(token.c_str());
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

std::vector<std::unique_ptr<Toy> > readToys(){
    return readToys("~/src/kaggle/elves/toys_rev2.csv");
}

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