#include "Animal.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    this->type = other.type;
    *this->brain = *other.brain;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "WAFFFF WAFFFFF" << std::endl;
}
