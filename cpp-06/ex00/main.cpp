#include "Conversion.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    Conversion test(av[1]);
    test.print();
}