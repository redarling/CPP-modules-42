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
        virtual std::string const & getName() const;
        virtual void                equip(AMateria* m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);

    private:
        std::string _name;
        AMateria*   _inventory[4]; 
};

#endif