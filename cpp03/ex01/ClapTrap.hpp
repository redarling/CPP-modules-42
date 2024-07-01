#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "string"

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& clapTrap);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& clapTrap);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

    private:
            std::string     name;
            unsigned int    hitPoints;
            unsigned int    energyPoints;
            unsigned int    attackDamage;
};

#endif