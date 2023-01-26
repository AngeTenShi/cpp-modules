#include "Animal.hpp"


Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    this->type = other.type;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Generic sound for animal MEUHHH" << std::endl;
}