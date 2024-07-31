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

            virtual void        learnMateria(AMateria*);
            virtual AMateria*   createMateria(std::string const & type);

};

#endif