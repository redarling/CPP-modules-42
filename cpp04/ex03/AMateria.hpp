#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "Character.hpp"
# include "MateriaSource.hpp"
# include <iostream>

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;

class AMateria
{
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        virtual             ~AMateria();
        AMateria&           operator=(const AMateria& other);

        std::string const&  getType() const;
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target) = 0;

    protected:
        std::string const   _type;
};

#endif