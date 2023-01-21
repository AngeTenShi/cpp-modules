#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap a;
    ScavTrap ab("Ange");
    ScavTrap abc;
    ClapTrap b("Maronneur");
    ClapTrap c(b);
    a = c;
    abc = ab;
    a.attack("Cibla");
    ab.attack("Gaia");
    ab.takeDamage(10);
    ab.beRepaired(50);
    a.takeDamage(50);
    a.beRepaired(100);
    ab.guardGate();
}