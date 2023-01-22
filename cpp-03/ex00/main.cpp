#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("Test");
    ClapTrap c(b);
    a = c;
    a.attack("target");
    a.takeDamage(50);
    a.beRepaired(100);


}