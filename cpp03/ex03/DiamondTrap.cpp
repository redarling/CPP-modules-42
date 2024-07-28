#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noname_clap_name"), 
                             ScavTrap(), 
                             FragTrap(), 
                             name("noname")
{
    std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
                                             ScavTrap(name), 
                                             FragTrap(name),
                                             name(name)
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap: " << this->name 
              << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap),
                                                           ScavTrap(diamondTrap), 
                                                           FragTrap(diamondTrap),
                                                           name(diamondTrap.name)
{
    std::cout << "DiamondTrap: " << this->name 
              << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: " << this->name 
              << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (this != &diamondTrap)
    {
        ClapTrap::operator=(diamondTrap);
        ScavTrap::operator=(diamondTrap);
        FragTrap::operator=(diamondTrap);
        this->name = diamondTrap.name;
        std::cout << "DiamondTrap: " << this->name 
                  << " copy assignment operator called" << std::endl;
    }
    
    return (*this);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My name: " << name << ". My ClapTrap name: " 
              << ClapTrap::name << std::endl;
}
