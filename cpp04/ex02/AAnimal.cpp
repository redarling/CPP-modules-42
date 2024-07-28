#include "AAnimal.hpp"

Animal::Animal() : type("unknown")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    (*this) = animal;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal&         Animal::operator=(const Animal& animal)
{
    if (this != &animal)
    {
        this->type = animal.getType();
        std::cout << "Animal copy assignment operator called" << std::endl;
    }
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal unknown sound..." << std::endl;
}

std::string     Animal::getType() const
{
    return (this->type);
}

void Animal::setBrainIdea(int index, const std::string& idea)
{
    std::cout << "This animal has no brain to set ideas." << std::endl;
}

std::string Animal::getBrainIdea(int index) const
{
    std::cout << "This animal has no brain to get ideas." << std::endl;
    return ("");
}