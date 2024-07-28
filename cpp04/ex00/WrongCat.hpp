#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& wrongCat);
        ~WrongCat();
        WrongCat&       operator=(const WrongCat& wrongCat);
        void            makeSound(void) const;
};

#endif