#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(Fixed &f);

    Fixed &operator=(Fixed &f);
    ~Fixed();
    int     getRawBits(void);
    void    setRawBits(int const raw);

private:
    int raw;
    static int const nb_bits = 8;
};

#endif