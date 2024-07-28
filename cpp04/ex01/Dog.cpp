#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog), _brain(new Brain(*dog._brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    delete (this->_brain);
    std::cout << "Dog destructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        Animal::operator=(dog);
        if (this->_brain)
            delete (this->_brain);
        this->_brain = new Brain(*dog._brain);
        std::cout << "Dog copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "BAAARK!!!!!!" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const
{
    return (_brain->getIdea(index));
}