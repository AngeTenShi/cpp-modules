#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::attack()
{
	if (this->weapon == NULL)
		std::cout << this->name << "Doesn't have a weapon to attack" << std::endl;
	std::cout << this->name << " attacks with their" << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}