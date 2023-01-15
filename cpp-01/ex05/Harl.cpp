#include "Harl.hpp"

Harl::~Harl()
{
    return ;
}

Harl::Harl()
{
    this->types[0] = "debug";
    this->f[0] = &Harl::debug;
    this->types[1] = "info";
    this->f[1] = &Harl::info;
    this->types[2] = "warning";
    this->f[2] = &Harl::warning;
    this->types[3] = "error";
    this->f[3] = &Harl::error;
    return ;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (!level.compare(this->types[i]))
            (this->*f[i])();
    }
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}