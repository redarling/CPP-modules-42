#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        Animal::operator=(dog);
        std::cout << "Dog copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "BAAARK!!!!!!" << std::endl;
}