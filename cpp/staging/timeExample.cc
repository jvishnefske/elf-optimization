#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <ctime>
#include <iomanip>
int main()
{
/*    std::wstring input = L"2011-Februar-18 23:12:34";
    std::tm t;
    std::wistringstream ss(input);
    ss.imbue(std::locale("de_DE"));
    ss >> std::get_time(&t, L"%Y-%b-%d %H:%M:%S"); // uses std::time_get<wchar_t>
    std::cout << std::asctime(&t);
*/  
    struct std::tm when;
    std::cout <<"Please,enter the time";
    //std::cin >> std::get_time(&when,"%R");
    //if(std::cin::fail()) std::cout <<"error reading time"<<std::endl;
    //else{
     //   std::cout <<"the time entered is: ";
     //   std::cout << when.tm_hour << " hours and " << when.tm_min << " minutes" <<std::endl;
    //}
}
