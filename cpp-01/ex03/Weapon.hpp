#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
public:
	 Weapon();
	 Weapon(std::string name);
	 ~Weapon();
	 std::string const &getType();
	 void	setType(std::string newType);

private:
	 std::string type;
};

#endif