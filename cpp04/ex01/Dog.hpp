#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& dog);
        ~Dog();
        Dog&            operator=(const Dog& dog);
        virtual void    makeSound(void) const;
        virtual void            setBrainIdea(int index, const std::string& idea);
        virtual std::string     getBrainIdea(int index) const;

    private:
        Brain*  _brain;
};

#endif
