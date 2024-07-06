#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();
        DiamondTrap&    operator=(const DiamondTrap& other);
        void            whoAmI();
        using           ScavTrap::attack;

    private:
        std::string     name;
};

#endif
