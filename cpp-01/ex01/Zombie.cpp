#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->name << " a laché sa pipe" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}