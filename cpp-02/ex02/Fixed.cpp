#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw = 0;
}

Fixed::Fixed(Fixed const &f)
{
    *this = f;
}

Fixed::Fixed(const int number)
{
    this->raw = (number << this->nb_bits);
}

Fixed::Fixed(const float number)
{
    this->raw = roundf(number * (1 << this->nb_bits));
}

Fixed::~Fixed()
{
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}

Fixed &Fixed::operator=(Fixed const &f)
{
    this->raw = f.getRawBits();
    return (*this);
}

int Fixed::toInt(void) const
{
    return (this->raw / (1 << this->nb_bits));
}

float Fixed::toFloat(void) const
{
    return (((float)this->raw / (1 << this->nb_bits)));
}

std::ostream &operator<<(std::ostream &stream, Fixed const &toprint)
{
    stream << toprint.toFloat();
    return (stream);
}

bool Fixed::operator>(const Fixed &f)
{
    return(this->toFloat() > f.toFloat());
}

bool Fixed::operator<(const Fixed &f)
{
    return(this->toFloat() < f.toFloat());
}

bool Fixed::operator>=(const Fixed &f)
{
    return (this->toFloat() >= f.toFloat());
}

bool Fixed::operator<=(const Fixed &f)
{
    return (this->toFloat() <= f.toFloat());
}

bool Fixed::operator==(const Fixed &f)
{
    return (this->toFloat() == f.toFloat());
}

bool Fixed::operator!=(const Fixed &f)
{
    return (this->toFloat() != f.toFloat());
}

Fixed Fixed::operator+(const Fixed &f)
{
    return(Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator-(Fixed const &f)
{
    return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator*(Fixed const &f)
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(Fixed const &f)
{
    return (this->toFloat() / f.toFloat());
}

Fixed &Fixed::operator++()
{
    this->raw++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->raw++;
    return (old);
}

Fixed &Fixed::operator--()
{
    this->raw--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    this->raw--;
    return (old);
}

Fixed Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1.toFloat() > f2.toFloat())
        return (Fixed(f1.toFloat()));
    else
        return (Fixed(f2.toFloat()));
}

Fixed Fixed::max(Fixed const &f1, Fixed const &f2)
{
    if (f1.toFloat() > f2.toFloat())
        return (Fixed(f1.toFloat()));
    else
        return (Fixed(f2.toFloat()));

}

Fixed Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1.toFloat() < f2.toFloat())
        return (Fixed(f1.toFloat()));
    else
        return (Fixed(f2.toFloat()));
}

Fixed Fixed::min(Fixed const &f1, Fixed const &f2)
{
    if (f1.toFloat() < f2.toFloat())
        return (Fixed(f1.toFloat()));
    else
        return (Fixed(f2.toFloat()));
}
