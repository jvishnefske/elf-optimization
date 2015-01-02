#include <iostream>
#include <random>
#include <ctime>
int main(int argc, char const *argv[])
{
	time_t now;
	std::time(&now);
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,64);
	generator.seed(now);
	generator.discard(2);

	int goal = distribution(generator);
	std::cout << "Guess a number 1-64 ("<<goal<<")"<<std::endl ;
	int guess;
	while (std::cin>>guess){
		if (guess<goal){
			std::cout<<"too low"<<std::endl;
		}else if (guess>goal){

			std::cout << "too high" << std::endl;
		}else{
			std::cout << "correct, you win."<<std::endl;
			break;
		}

	}

	return 0;
}