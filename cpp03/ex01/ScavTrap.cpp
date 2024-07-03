#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noname")
{
    this->attackDamage = 20;
    this->hitPoints = 100;
    this->energyPoints = 50;
    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->attackDamage = 20;
    this->hitPoints = 100;
    this->energyPoints = 50;
    std::cout << "ScavTrap: " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
    std::cout << "ScavTrap: " << this->name << " copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: " << this->name << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        ClapTrap::operator=(scavTrap);
        std::cout << "ScavTrap: " << this->name << " copy assignment operator called" << std::endl;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " can't attack " << target << " because it has no hit points left." << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " can't attack " << target << " because it has no energy points left." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
    std::cout << "ScavTrap " << name << " has " << energyPoints << " energy point(s) left." << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}