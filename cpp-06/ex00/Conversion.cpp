#include "Conversion.hpp"
#include <cstdlib>
#include <iomanip>

Conversion::Conversion(char *input)
{
    this->input = input;
    this->manip_input.assign(input);
    this->is_char = false;
    this->is_int = false;
    this->is_float = false;
    this->is_double = false;
    this->is_special = false;
}

Conversion::~Conversion()
{
    return ;
}

Conversion::Conversion(const Conversion &other)
{
    this->input = other.input;
    this->is_int = other.is_int;
    this->is_char = other.is_char;
    this->is_float = other.is_float;
    this->is_double = other.is_double;
    this->is_special = other.is_special;
}

Conversion &Conversion::operator=(const Conversion &other)
{
    this->input = other.input;
    this->is_int = other.is_int;
    this->is_char = other.is_char;
    this->is_float = other.is_float;
    this->is_double = other.is_double;
    this->is_special = other.is_special;
    return (*this);
}

void Conversion::detect_type()
{
    std::string particular_f[3] = {"+inff", "-inff", "nanf"};
    std::string particular_d[3] = {"+inf", "-inf", "nan"};
    if ((this->manip_input).size() == 1 && isascii(this->manip_input[0]))
    {
        this->is_char = true;
        return;
    }
    if ((this->manip_input).find(".") != std::string::npos && (this->manip_input[this->manip_input.size() - 1]) == 'f')
    {
        this->is_float = true;
    }
    if ((this->manip_input).find(".") != std::string::npos)
    {
        if (this->is_float == false)
            this->is_double = true;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (!this->manip_input.compare(particular_f[i]) || !this->manip_input.compare(particular_d[i]))
        {
            this->is_special = true;
            return ;
        }
    }
    for (int i = 0; this->input[i]; i++)
    {
        if (!isdigit(this->input[i]) && !(this->input[i] == '-' || this->input[i] == '+'))
            return ;
    }
    this->is_int = true;
}


void Conversion::print()
{
    std::string particular_f[3] = {"+inff", "-inff", "nanf"};
    std::string particular_d[3] = {"+inf", "-inf", "nan"};

    this->detect_type();
    if (this->is_char)
    {
        std::cout << "char : " << this->input[0] << std::endl;
        std::cout << "int : " << static_cast<int>(std::atoi(&this->input[0])) << std::endl;
        std::cout << "float : " << static_cast<float>(std::atof(&this->input[0])) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(std::atof(&this->input[0])) << ".0" << std::endl;
    }
    else if (this->is_float)
    {
        float to_print = static_cast<float>(std::atof(this->input));
        int printable = static_cast<int>(to_print);
        if (printable >= 32 && printable <= 127)
            std::cout << "char : " << static_cast<char>(static_cast<int>(to_print)) << std::endl;
        else
            std::cout << "char : " << "not possible" << std::endl;
        std::cout << "int : " << static_cast<int>(to_print) << std::endl;
        std::cout << "float : " << to_print << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(to_print) << std::endl;
    }
    else if (this->is_double)
    {
        double to_print = std::strtod(this->input, NULL);
        int printable = static_cast<int>(to_print);
        if (printable >= 32 && printable <= 127)
            std::cout << "char : " << static_cast<char>(static_cast<int>(to_print)) << std::endl;
        else
            std::cout << "char : " << "not possible" << std::endl;
        std::cout << "int : " << static_cast<int>(to_print) << std::endl;
        std::cout << "float : " << static_cast<float>(to_print)  << "f" << std::endl;
        std::cout << "double : " << to_print << std::endl;
    }
    else if (this->is_special)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!this->manip_input.compare(particular_f[i]) || !this->manip_input.compare(particular_d[i]))
            {
                std::cout << "char : not possible" << std::endl;
                std::cout << "int : not possible" << std::endl;
                std::cout << "float : " << particular_f[i] << std::endl;
                std::cout << "double : " << particular_d[i] << std::endl;
                return ;
            }
        }
    }
    else if (this->is_int)
    {
        int to_print = static_cast<int>(std::atoi(this->input));
        if (to_print >= 32 && to_print <= 127)
            std::cout << "char : " << static_cast<char>(to_print) << std::endl;
        else
            std::cout << "char : " << "not possible" << std::endl;
        std::cout << "int : " << to_print << std::endl;
        std::cout << "float : " << static_cast<float>(to_print) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(to_print) << ".0" << std::endl;
    }
    else
        std::cout <<  "Input valid scalar types" << std::endl;
}