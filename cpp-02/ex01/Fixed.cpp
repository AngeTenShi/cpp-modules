#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->raw = (number << this->nb_bits);
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->raw = roundf(number * (1 << this->nb_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}

Fixed &Fixed::operator=(Fixed const &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = f.getRawBits();
    return (*this);
}

int Fixed::toInt() const
{
    return (this->raw / (1 << this->nb_bits));
}

float Fixed::toFloat() const
{
    return (((float)this->raw / (1 << this->nb_bits)));
}

std::ostream &operator<<(std::ostream &stream, Fixed const &toprint)
{
    stream << toprint.toFloat();
    return (stream);
}
