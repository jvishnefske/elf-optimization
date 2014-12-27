#include <iostream>
#include "main.h"
#include <getopt.h>

extern void read(void);
int main(int argc, char *argv[])
{
    //for another example of getopt int cpp see:
    // http://www.chemie.fu-berlin.de/chemnet/use/info/libgpp/libgpp_39.html
    std::string inputFile = "../toys_rev2.csv.gz";
    int verbose_flag, help_flag;
    int choice;
    while (1)
    {
        static struct option long_options[] =
        {
            /* Use flags like so:
            {"verbose",	no_argument,	&verbose_flag, 'V'}*/
            /* Argument styles: no_argument, required_argument, optional_argument */
            {"version", no_argument,	0,	'v'},
            {"help",	no_argument,	0,	'h'},
            {"input-file", no_argument,  0,      'i'},
            {0,0,0,0}
        };
    
        int option_index = 0;
    
        /* Argument parameters:
            no_argument: " "
            required_argument: ":"
            optional_argument: "::" */
    
        choice = getopt_long( argc, argv, "vhi",
                    long_options, &option_index);
    
        if (choice == -1)
            break;
    
        switch( choice )
        {
            case 'v': verbose_flag = 1;
                
                break;
    
            case 'h': help_flag = 1;
                std::cout<<argv[0]<< " [-i inputfile]"<<std::endl;
                
                break;
    
            case '?':
                /* getopt_long will have already printed an error */
                break;
    
            default:
                /* Not sure how to get here... */
                return EXIT_FAILURE;
        }
    }
    
    /* Deal with non-option arguments here */
    if ( optind < argc )
    {
        while ( optind < argc )
        {
            ++optind;
        }
    }
    std::cout << "parse input file: "<<inputFile<<std::endl;
    
    /*
    std::string line ("1,2014 1 2 0 0,14");
    std::cout<<line<<std::endl;I
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
    */
}
