#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        Animal::operator=(cat);
        std::cout << "Cat copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow.. meow" << std::endl;
}