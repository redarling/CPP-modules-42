#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("unknown")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    (*this) = wrongAnimal;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&         WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    if (this != &wrongAnimal)
    {
        this->type = wrongAnimal.getType();
        std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal unknown sound..." << std::endl;
}

std::string     WrongAnimal::getType() const
{
    return (this->type);
}