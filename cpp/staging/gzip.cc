#include "main.h" //struct Toy{id,arrivalTime,duration};
//memory,iostream,string
#include <fstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <vector>
//#include <memory>
#include <ctime>
#include <sstream> //stringstream
//#define FILENAME  "../toys_rev2.csv.gz";
#define FILENAME "./toys.csv"
read
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
/*
void readStream(filestd::istream){
    
    //std::ifstream file(FILENAME,std::ios_base::in);
    std::string line;

    int i=0;
    while (file>>line){
        std::cout<<"["<<i<<"]"<<line<<std::endl;
        i++;
    }
}*/
std::vector<std::unique_ptr<Toy> > readToys(std::istream &stream){
    std::vector<std::unique_ptr<Toy> > toyBox;
    std::ifstream file(FILENAME);
    std::string line;
    std::getline(stream,line);//read header line.
    while(std::getline(stream,line)){
        std::istringstream lineStream(line);
        std::string cell;
        Toy *toy = new Toy();
        lineStream >> toy->id;
        std::getline(lineStream,cell,',');
        std::getline(lineStream,cell,',');
        toy->duration = strToRel(cell.c_str());   
        lineStream>>toy->duration;
        toyBox.push_back(std::unique_ptr<Toy> (toy));
    }
    return toyBox;
}
