#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
}
        
Cure::~Cure()
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Cure copy assignment operator called" << std::endl;
    }
    return (*this);
}
        
AMateria*   Cure::clone() const
{

}

void        Cure::use(ICharacter& target)
{

}