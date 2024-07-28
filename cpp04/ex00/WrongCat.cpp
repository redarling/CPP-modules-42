#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& wrongCat)
{
    if (this != &wrongCat)
    {
        WrongAnimal::operator=(wrongCat);
        std::cout << "WrongCat copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Fake meow..." << std::endl;
}