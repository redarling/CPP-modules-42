#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Cure& other) : AMateria(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
}
        
Ice::~Ice()
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Ice copy assignment operator called"
                  << std::endl;
    }
    return (*this);
}
        
AMateria*   Ice::clone() const
{
    AMateria*   cloned = (*this);

    return (cloned);
}

void        Ice::use(ICharacter& target)
{
        std::cout << "Ice: * heals "
                  << target.getName() << "'s wounds *"
                  << std::endl;
}