#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& cat);
        ~Cat();
        Cat&            operator=(const Cat& cat);
        virtual void    makeSound(void) const;
        virtual void            setBrainIdea(int index, const std::string& idea);
        virtual std::string     getBrainIdea(int index) const;

    private:
        Brain*  _brain;

};

#endif