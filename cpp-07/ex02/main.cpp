#include "Array.hpp"

int main(void)
{
    Array <int> test;
    Array <int> test2(5);
    Array <char> test3(5);

    std::cout << test2[4] << std::endl;
    test2[4] = 26;
    std::cout << test2[4] << std::endl;
    test3[0] = 'a';
    std::cout << test3[0] << std::endl;
    try
	{	
		std::cout << test2[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}
