#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &f);
    Fixed(int const number);
    Fixed(float const number);
    Fixed &operator=(Fixed const &f);
    ~Fixed();

    float   toFloat(void) const;
    int     toInt(void) const;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private:
    int raw;
    static int const nb_bits = 8;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &toprint);

#endif