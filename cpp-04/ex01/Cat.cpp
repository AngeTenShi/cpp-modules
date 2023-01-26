#include "Animal.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    this->type = other.type;
    *this->brain = *other.brain;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "MIAOUUUUUUUUUU" << std::endl;
}