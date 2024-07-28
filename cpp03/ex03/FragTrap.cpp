#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("noname")
{
    this->attackDamage = 30;
    this->hitPoints = 100;
    this->energyPoints = 100;
    std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->attackDamage = 30;
    this->hitPoints = 100;
    this->energyPoints = 100;
    std::cout << "FragTrap: " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap)
{
    std::cout << "FragTrap: " << this->name 
              << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: " << this->name 
              << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    if (this != &fragTrap)
    {
        ClapTrap::operator=(fragTrap);
        std::cout << "FragTrap: " << this->name 
                  << " copy assignment operator called" << std::endl;
    }
    return (*this);
}

void        FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests high fives!" << std::endl;
}