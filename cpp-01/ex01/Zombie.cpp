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

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde;
	int i = 0;

	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].setName(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}