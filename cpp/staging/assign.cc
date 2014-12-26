    #include <boost/assign/std/vector.hpp> // for 'operator+=()'
    #include <boost/assert.hpp> 
    //using namespace std;
    using namespace boost::assign; // bring 'operator+=()' into scope
int main(int argc, char *argv[])
    {
        std::vector<int> values;  
        values += 1,2,3,4,5,6,7,8,9; // insert values at the end of the container
        BOOST_ASSERT( values.size() == 9 );
        BOOST_ASSERT( values[0] == 1 );
        BOOST_ASSERT( values[8] == 9 );
        for (auto i : values) {
            std::cout << "i: " << i << std::endl;
        }
    }
