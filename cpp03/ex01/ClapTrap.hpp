#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <limits>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& clapTrap);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& clapTrap);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

    protected:
            std::string     name;
            unsigned int    hitPoints;
            unsigned int    energyPoints;
            unsigned int    attackDamage;
};

#endif