#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
                MateriaSource();
                MateriaSource(const MateriaSource& other);
                ~MateriaSource();
                MateriaSource& operator=(const MateriaSource& other);
                
                virtual void        learnMateria(AMateria* m);
                virtual AMateria*   createMateria(std::string const & type);

    private:
                AMateria*   _inventory[4];
                void        clearSource();
                void        copySource(const MateriaSource& other);

};

#endif