#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
public:
    FlagTrap();
    FlagTrap(std::string name);
    FlagTrap(const FlagTrap &t);
    FlagTrap &operator=(const FlagTrap &other);
    ~FlagTrap();

    void    highFivesGuys(void);
};

#endif