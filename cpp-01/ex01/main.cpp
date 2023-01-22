#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;

	horde = zombieHorde(30, "Saspi");
	delete [] horde;
}