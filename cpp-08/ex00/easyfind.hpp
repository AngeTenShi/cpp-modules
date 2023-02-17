#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
int easyfind(T first_occ, int number)
{
    typename T::iterator it;
    it = std::find(first_occ.begin(), first_occ.end(), number);
    if (it != first_occ.end())
        std::cout << "Element found" << std::endl;
    else
    {
        std::cout << "Element not found" << std::endl;
        return (-1);
    }
    return (0);
}

#endif