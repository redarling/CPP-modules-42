#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& animal);
        virtual         ~WrongAnimal();
        WrongAnimal&    operator=(const WrongAnimal& wrongAnimal);
        void            makeSound(void) const;
        std::string     getType() const;

    protected:
            std::string type;
            
};

#endif