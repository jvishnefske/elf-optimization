#include <iostream>
extern void read(void);
int main(int argc, char *argv[])
{
    std::string text = "reading file";
    std::cout<<text<<std::endl;
    read();
    return 0;
}
