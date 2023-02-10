#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>

class Conversion
{
public:
    Conversion(char *input);
    Conversion(Conversion const &other);
    Conversion &operator=(Conversion const &other);
    ~Conversion();
    void    detect_type();
    void    print();
private:
    bool is_char;
    bool is_int;
    bool is_float;
    bool is_double;
    bool is_special;
    char *input;
    std::string manip_input;
    float   val_float;
    int     val_int;
    char    val_char;
    double  val_double;
};

#endif