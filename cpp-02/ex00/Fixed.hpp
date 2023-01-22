#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &f);

    Fixed &operator=(const Fixed &f);
    ~Fixed();
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private:
    int raw;
    static int const nb_bits = 8;
};

#endif