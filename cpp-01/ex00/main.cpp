#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie1("Foo");
	Zombie *zombie2;
	zombie2 = newZombie("Claude");
	zombie1.announce();
	zombie2->announce();
	randomChump("Matteo");
	delete zombie2;
	return (0);
}