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
    Fixed operator+(Fixed const &f);
    Fixed operator-(Fixed const &f);
    Fixed operator*(Fixed const &f);
    Fixed operator/(Fixed const &f);
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    bool operator>(Fixed const &f);
    bool operator<(Fixed const &f);
    bool operator>=(Fixed const &f);
    bool operator<=(Fixed const &f);
    bool operator==(Fixed const &f);
    bool operator!=(Fixed const &f);
    ~Fixed();

    float       toFloat(void) const;
    int         toInt(void) const;
    int         getRawBits(void) const;
    void        setRawBits(int const raw);
    static Fixed min(Fixed &f1, Fixed &f2);
    static Fixed min(Fixed const &f1, Fixed const &f2);
    static Fixed max(Fixed &f1, Fixed &f2);
    static Fixed max(Fixed const &f1, Fixed const &f2);

private:
    int raw;
    static int const nb_bits = 8;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &toprint);

#endif