#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "Scav Trap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor with name called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    this->name = other.name;
    this->energy_points = other.energy_points;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap entered in gate keeper mode" << std::endl;
}