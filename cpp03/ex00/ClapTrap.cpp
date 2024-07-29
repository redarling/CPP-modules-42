#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
            : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap: " << this->name 
              << " constructor called" << std::endl;
}

ClapTrap::ClapTrap() 
    : name("noname"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    std::cout << "ClapTrap: " << this->name 
              << " copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: " << this->name 
              << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    if (this != &clapTrap)
    {
        this->name = clapTrap.name;
        this->attackDamage = clapTrap.attackDamage;
        this->energyPoints = clapTrap.energyPoints;
        this->hitPoints = clapTrap.hitPoints;
        std::cout << "ClapTrap: " << this->name 
                  << " copy assignment operator called" << std::endl;
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
        std::cout << "ClapTrap " << this->name 
                  << " can't be repaired, because he has no energy point(s) left." 
                  << std::endl;
        return;
    }

    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name
                  << " can't be repaired, because he is DEAD."
                  << std::endl;
        return;
    }

    if (this->hitPoints == std::numeric_limits<unsigned int>::max() || 
        amount > std::numeric_limits<unsigned int>::max() - this->hitPoints)
    {
        this->hitPoints = std::numeric_limits<unsigned int>::max();
        std::cout << "ClapTrap " << this->name << " hit points are now at max." << std::endl;
    }
    else
    {
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " was repaired by "
                  << amount << " point(s)." << std::endl;
    }
    
    this->energyPoints--;
    
    std::cout << "ClapTrap " << this->name << " has " 
            << this->energyPoints << " energy point(s) and " 
            << this->hitPoints << " hit point(s) now." << std::endl;
}