#include <iostream>
#include "iter.hpp"

void    increment(int &x)
{
    x++;
}


int main()
{
    int tab[3] = {1,2,3};
    iter(tab, 3, increment);
    std::cout << tab[0] << std::endl;
    std::cout << tab[1] << std::endl;
    std::cout << tab[2] << std::endl;
    return (0);
}