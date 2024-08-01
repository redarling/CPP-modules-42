#include "Character.hpp"

Character::Character() : _name("noname"), _inventory()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name), _inventory()
{
    std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
    delete[] (_inventory);
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& other)
{
    (*this) = other;
    std::cout << "Character copy constructor called" << std::endl;
}

Character&  Character::operator=(const Character& character)
{
    if (*this != &other)
    {
        // delete inventory
        this->_name = character->_name;
        // copy inventory
        std::cout << "Character copy assignment operator called"
                  << std::endl;
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void    Character::equip(AMateria* m)
{

}

void    Character::unequip(int idx)
{

}

void    Character::use(int idx, ICharacter& target)
{

}