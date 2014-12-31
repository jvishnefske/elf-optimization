#include <iostream>
#include <algorithm>
#include <vector>
#include "../readcsv.h"
#include "../main.h"

inline int divide(int a, double b){
    return (int)a/b;
};

class ElfCompareEfficency{
public:
    bool operator() (&Elf e1,&Elf &e2)
    {
        return e1.efficency < e2.efficency;

    }

} elfCompareEfficency;

//create a heuristic container given a hype, and a comparison function.
// the comparison function is 
int main(int argc, char *argv[])
{
    for(int i=1;i<5;++i){


  
        std::cout  << std::endl;
    }   
    return 0;
}
