#include "Animal.hpp"


AAnimal::AAnimal()
{
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}