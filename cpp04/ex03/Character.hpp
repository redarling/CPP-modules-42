#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character& other);
        Character&  operator=(const Character& character);

    private:
        
};

#endif