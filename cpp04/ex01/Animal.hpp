#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& animal);
        virtual             ~Animal();
        Animal&             operator=(const Animal& animal);
        virtual void        makeSound(void) const;
        std::string         getType() const;
        virtual void        setBrainIdea(int index, const std::string& idea);
        virtual std::string getBrainIdea(int index) const;

    protected:
            std::string     type;
            
};

#endif