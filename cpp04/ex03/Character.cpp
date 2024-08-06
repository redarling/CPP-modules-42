#include "Character.hpp"

Character::Character() : _name("noname")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = nullptr;
    for (int i = 0; i < 100; ++i)
        this->_unequippedMaterias[i] = nullptr;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = nullptr;
    for (int i = 0; i < 100; ++i)
        this->_unequippedMaterias[i] = nullptr;
}

Character::~Character()
{
    clearInventory();
    clearUnequippedMaterias();
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = nullptr;
    for (int i = 0; i < 100; ++i)
        this->_unequippedMaterias[i] = nullptr;
    std::cout << "Character copy constructor called" << std::endl;
    copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        clearInventory();
        clearUnequippedMaterias();
        this->_name = other.getName();
        copyInventory(other);
        std::cout << "Character copy assignment operator called" << std::endl;
    }
    return (*this);
}


std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] != nullptr)
        {
            delete (this->_inventory[i]);
            this->_inventory[i] = nullptr;
        }
    }
}

void Character::clearUnequippedMaterias()
{
    for (int i = 0; i < 100; ++i)
    {
        if (this->_unequippedMaterias[i] != nullptr)
        {
            delete (this->_unequippedMaterias[i]);
            this->_unequippedMaterias[i] = nullptr;
        }
    }
}

void Character::copyInventory(const Character& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i] != nullptr)
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = nullptr;
    }
}

void    Character::dropMateria(int idx)
{
    for (int i = 0; i < 100; ++i)
    {
        if (this->_unequippedMaterias[i] == nullptr)
        {
            this->_unequippedMaterias[i] = this->_inventory[idx];
            this->_inventory[idx] = nullptr;
            std::cout << "Materia dropped" << std::endl;
            return ;
        }
    }
    std::cout << "Too many dropped materias, it's not possible to drop more!" << std::endl;
}

void    Character::equip(AMateria* m)
{
    if (m == nullptr)
    {
        std::cout << "Materia doesn't exist. Error!" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] == nullptr)
        {
            this->_inventory[i] = m->clone();
            return;
        }
    }
    std::cout << this->_name << ": inventory is full!" << std::endl;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << this->getName() << ": wrong slot index!" << std::endl;
        return ;
    }
    if (this->_inventory[idx] == nullptr)
    {
        std::cout << this->getName() << ": slot is empty" << std::endl;
        return ;
    }
    dropMateria(idx);
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << this->getName() << ": wrong slot index!" << std::endl;
        return ;
    }
    if (this->_inventory[idx] == nullptr)
    {
        std::cout << this->getName() << ": slot is empty" << std::endl;
        return ;
    }
    this->_inventory[idx]->use(target);
}
