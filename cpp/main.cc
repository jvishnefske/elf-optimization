#include <iostream>
#include "main.h"

extern void read(void);
int main(int argc, char *argv[])
{
    std::string line ("1,2014 1 2 0 0,14");
    std::cout<<line<<std::endl;
    std::stringstream lineStream(line);
    Toy toy;
    lineStream >> toy.id;
    std::string token;
    std::getline(lineStream,token,',');
    std::getline(lineStream,token,',');
    toy.arrivalTime = strToRel(token.c_str());
    lineStream >> toy.duration;
    std::cout << toy.toString() << std::endl;
    return 0;
}
