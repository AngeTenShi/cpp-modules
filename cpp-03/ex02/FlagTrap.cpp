#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap()
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 20;
    std::cout << "FlagTrap Default Constructor called" << std::endl;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FlagTrap Constructor with name called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 20;
}

FlagTrap::FlagTrap(const FlagTrap &t) :ClapTrap(t)
{
    std::cout << "FlagTrap Copy Constructor called" << std::endl;
}

FlagTrap::~FlagTrap()
{
    std::cout << "FlagTrap Destructor called" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
    this->name = other.name;
    this->attack_damage = other.attack_damage;
    this->energy_points = other.energy_points;
    this->hit_points = other.hit_points;
    return (*this);
}

void FlagTrap::highFivesGuys()
{
    std::cout << "FlagTrap " << this->name << " ask an high five" << std::endl;
}