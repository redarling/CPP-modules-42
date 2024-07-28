#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat), _brain(new Brain(*cat._brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    delete (this->_brain);
    std::cout << "Cat destructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        Animal::operator=(cat);
        if (this->_brain)
            delete (_brain);
        this->_brain = new Brain(*cat._brain);
        std::cout << "Cat copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow.. meow" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const
{
    return (_brain->getIdea(index));
}