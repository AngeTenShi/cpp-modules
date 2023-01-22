#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie1("Foo");
	Zombie *zombie2;
	zombie2 = newZombie("Claude");
	randomChump("Matteo");
	delete zombie2;
	return (0);
}