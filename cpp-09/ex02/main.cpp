#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./PmergeMe sequence" << std::endl;
        return (1);
    }
    PmergeMe test(av, ac);
    test.run();
    return (0);
}