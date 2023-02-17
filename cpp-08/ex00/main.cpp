#include "easyfind.hpp"
#include <vector>
#include <list>
#include <map>

int main(void)
{
    std::vector<int> v(2,42);
    std::list<int> list;
    list.push_back(3);
    v.push_back(5);
    easyfind(v, 5);
    easyfind(list, 5);
    return (0);
}