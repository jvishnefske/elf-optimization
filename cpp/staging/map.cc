#include <vector>
#include <map>
#include <iostream>
#include <memory>
//#include <boost/iostream/>
class queue
{


	//queue();
	//~queue();
	//add(){}
};



int main(int argc, char const *argv[])
{
	std::multimap<int,int> mm;
	mm.insert(std::pair<int,int>(1,1));
	mm.insert(std::pair<int,int>(0,1));
	mm.insert(std::pair<int,int>(2,3));
	std::map<int,int> q;
	for(auto e :q.find(1);){
		std::cout<<e.first<<std::endl;

	}


	/* code */
	return 0;
}

