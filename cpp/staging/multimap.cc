#include <iostream>
#include <map>
#include <vector>
#include <boost/assign/std/vector.hpp>
#include <boost/assert.hpp>
using namespace boost::assign;
int main(int argc, char *argv[])
    //http://www.boost.org/doc/libs/1_38_0/libs/assign/doc/index.html
    //
{
    std::multimap<int,int> m;
    //iterator insert(iterator,iterator)
    //iterator insert(value_type &val)
    //iterator insert() 
    //std::vector<int> items; // items{1,2,3};
    //items += 1,2,3,5;
    //int i =0;
    //i+= 1,2,3;
    //std::cout << "i:" << i << std::endl;
    //m.insert(items.begin(), items.end());
    //boost::assign(m)(1,1)(1,2)(3,4);
    auto items = std::vector<int>({1,2,3,5});
    for (auto i : m) {
        //std:pair<int,int> i;
            
            std::cout << "item: " << i.first <<" " << i.second << std::endl;   
    }
    return 0;
}
