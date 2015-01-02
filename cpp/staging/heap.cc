#include <iostream>
#include <algorithm>
#include <random>


class Elf{
	public:
	int id;
	int duration;
};
class ElfDuration:Elf{
  public:
	//ElfDuration(int _id,int _duration):Elf(), Elf::id(_id), Elf::duration(_duration){}
	bool operator<(const ElfDuration & second){
		return Elf::duration < second.duration;
	}
};
void sortedVector(){
	std::vector<ElfDuration> a;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,10);
	generator.seed(12312);
	for (int i = 0; i < 20; ++i)
	{
		int duration = distribution(generator);
		int id = distribution(generator);
		//a.push_back(ElfDuration{id, duration});
	}
}

void heap(){
	std::vector<int> a;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,10);

	for (int i = 0; i < 100; ++i)
	{
		a.push_back(distribution(generator));
		std::push_heap(a.begin(),a.end());

		/* code */
	}
	//for(auto i = std)
	
	std::cout << std::endl;
	//return 0;
}

int main(int argc, char const *argv[])
{
	sortedVector();
}