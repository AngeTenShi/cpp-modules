#include "Harl.hpp"

int main(void)
{
    Harl Arlo;

    Arlo.complain("debug");
    std::cout << std::endl;
    Arlo.complain("info");
    std::cout << std::endl;
    Arlo.complain("warning");
    std::cout << std::endl;
    Arlo.complain("error");
}