#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(std::string name);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        
        virtual std::string const&  getName() const;
        virtual void                equip(AMateria* m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);

    private:
        std::string                 _name;
        AMateria*                   _inventory[4];
        AMateria*                   _unequippedMaterias[100];
        void                        clearInventory();
        void                        clearUnequippedMaterias();
        void                        dropMateria(int idx);
        void                        copyInventory(const Character& other);
};

#endif
