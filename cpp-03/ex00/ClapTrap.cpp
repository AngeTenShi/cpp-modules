#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &target)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = target;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    this->name = other.name;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    this->hit_points = other.hit_points;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energy_points <= 0 || this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " Can't attack no energy left" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " Can't take damage because already dead or has no energy left" << std::endl;
        return ;
    }
    if (this->hit_points >= 0)
        this->hit_points -= amount;
    if (this->hit_points <= 0)
        this->hit_points = 0;
    std::cout << "ClapTrap " << this->name << " take damage and has now " << this->hit_points << " hitpoints" << std::endl;
    if (this->hit_points <= 0)
    {
        this->hit_points = 0;
        std::cout << "ClapTrap " << this->name << " died" << std::endl;
        return ;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no more energy left" << std::endl;
        return ;
    }
    this->energy_points -= 1;
    this->hit_points += amount;
    std::cout << "ClapTrap " << this->name << " get repaired +" << amount << std::endl;
}