#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = brain.ideas[i];
        }
    }
    return (*this);
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
    {
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return (this->ideas[index]);
    }
    return ("");
}
