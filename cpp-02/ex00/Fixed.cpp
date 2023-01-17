#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->raw = f.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}

Fixed &Fixed::operator=(Fixed &f)
{
    this->raw = f.getRawBits();
    return (*this);
}