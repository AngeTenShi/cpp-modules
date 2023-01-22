#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	&(this->weapon) = weapon.getType();
}

HumanA::~HumanA()
{
	return ;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their" << (this->weapon).getType() << std::endl;
}