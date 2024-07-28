#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "---------------------" << std::endl;

    const Animal*       meta    = new Animal();
    const Animal*       j       = new Dog();
    const Animal*       i       = new Cat();
    const WrongAnimal*  wrong   = new WrongCat();
    
    std::cout << "---------------------" << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "---------------------" << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "---------------------" << std::endl;

    std::cout << wrong->getType() << " " << std::endl;
    wrong->makeSound();

    std::cout << "---------------------" << std::endl;

    delete (meta);
    delete (j);
    delete (i);
    delete (wrong);

    std::cout << "---------------------" << std::endl;
    
    return (0);
}