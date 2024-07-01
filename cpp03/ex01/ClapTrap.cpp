#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
    this->attackDamage = 0;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->name = name;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    if (this != &clapTrap)
    {
        this->name = clapTrap.name;
        this->attackDamage = clapTrap.attackDamage;
        this->energyPoints = clapTrap.energyPoints;
        this->hitPoints = clapTrap.hitPoints;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack "
                << target << ", because he has no hit points left."
                << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack "
                << target << ", because he has no energy points left."
                << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks "
              << target << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
    this->energyPoints--;

    std::cout << "ClapTrap " << this->name << " has "
            << this->energyPoints << " energy point(s) left."
            << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't took "
                  << amount << " point(s) of damage, " 
                  << "because he has no hit points left." << std::endl;  
    }
    
    std::cout << "ClapTrap " << this->name << " took "
              << amount << " point(s) of damage!" << std::endl;
    
    if (this->hitPoints > amount)
        this->hitPoints -= amount;
    else
        this->hitPoints = 0;
    
    std::cout << "ClapTrap " << this->name << " has "
              << this->hitPoints << " hit point(s) left."
              << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't be repaired"
                << ", because he has no energy point(s) left."
                << std::endl;
        return ;
    }

    if (this->hitPoints + amount > 10)
        this->hitPoints = 10;
    else
        this->hitPoints += amount;
    
    std::cout << "ClapTrap " << this->name << " was repaired by "
            << amount << " point(s)." << std::endl;
    
    this->energyPoints--;
    
    std::cout << "ClapTrap " << this->name << " has "
            << this->energyPoints << " energy point(s) and "
            << this->hitPoints << " hit point(s) now." << std::endl;
}