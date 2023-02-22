#include "Span.hpp"

int main()
{
    std::srand(time(NULL));
    std::vector<int> v(10000);
    std::generate(v.begin(), v.end(), std::rand);
    Span sp2 = Span(10000);
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
	sp2.addRangeNumber(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    std::cout << sp2.shortestSpan() << std::endl;
	try
	{
		sp.addNumber(5);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}
