#include "AMateria.hpp"

AMateria::AMateria() : _type("mystic")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        std::cout << "AMateria copy assignment operator called" << std::endl;
    }
    return (*this);
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}
