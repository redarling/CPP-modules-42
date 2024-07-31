#ifndef AANIMAL_HPP
# define AANIMAL_HPP

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
        virtual void        makeSound(void) const = 0;
        std::string         getType() const;
        virtual void        setBrainIdea(int index, const std::string& idea) = 0;
        virtual std::string getBrainIdea(int index) const = 0;

    protected:
            std::string     type;
            
};

#endif