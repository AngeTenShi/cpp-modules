#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"expression\"" << std::endl;
        return (1);
    }
    RPN rpn(av[1]);
    rpn.calculate();
    return (0);
}