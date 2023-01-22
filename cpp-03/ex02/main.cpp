#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main(void)
{
    ClapTrap a;
    ScavTrap ab("Ange");
    ScavTrap abc;
    FlagTrap flag("El Flago");
    ClapTrap b("Maronneur");
    FlagTrap flag2;
    FlagTrap flag3(flag2);
    ClapTrap c(b);
    flag2 = flag;
    a = c;
    abc = ab;
    a.attack("Cibla");
    ab.attack("Gaia");
    ab.takeDamage(10);
    ab.beRepaired(50);
    flag2.attack("Flaga Target");
    flag2.highFivesGuys();
    flag.highFivesGuys();
    a.takeDamage(50);
    a.beRepaired(100);
    ab.guardGate();
}