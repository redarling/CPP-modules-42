#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default construstor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    copySource(other);
}

MateriaSource::~MateriaSource()
{
    clearSource();
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        clearSource();
        copySource(other);
        std::cout << "MateriaSource copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (m == nullptr)
    {
        std::cout << "Error: Materia is null!" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] == nullptr)
        {
            this->_inventory[i] = m;
            std::cout << _inventory[i]->getType() << " materia learnt" << std::endl; 
            return ;
        }
    }
    std::cout << "Source is full!" << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 3; i >= 0; --i)
    {
        if (this->_inventory[i] != nullptr && this->_inventory[i]->getType() == type)
            return (this->_inventory[i]->clone());
    }
    std::cout << "Unknown materia type or source doesn't include it" << std::endl;
    return (nullptr);
}

void    MateriaSource::clearSource()
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

void        MateriaSource::copySource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i] != nullptr)
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = nullptr;
    }
}