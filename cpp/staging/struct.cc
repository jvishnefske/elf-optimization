#include <iostream>
class Car{
    public:
        int door ;//= 1;

};
int main(int argc, char *argv[])
{
    Car car;
    car.door=1;
    std::cout << car.door << std::endl;
    return 0;
}
