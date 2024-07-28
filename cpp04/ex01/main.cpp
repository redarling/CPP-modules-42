#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << std::endl;
    /******** SUBJECT *************************** */

    const Animal*   dog = new Dog();
    const Animal*   cat = new Cat();

    delete (cat);
    delete (dog);

    std::cout << std::endl;
    /******** BASIC TEST ************************ */

    const int       SIZE = 10;
    Animal*         animals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog();

    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << animals[i]->getType() << " says ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < SIZE; ++i)
        animals[i]->setBrainIdea(0, "I'm cool");

    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << animals[i]->getType() << " thinks: "
                  << animals[i]->getBrainIdea(0) << std::endl;
    }

    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

    std::cout << std::endl;
    /******** DEEP COPY TEST ******************** */

    Dog             originalDog;
    Cat             originalCat;

    originalDog.setBrainIdea(0, "Original Dog Idea");
    originalCat.setBrainIdea(0, "Original Cat Idea");

    Dog             copiedDog = originalDog;
    Cat             copiedCat = originalCat;
    
    originalDog.setBrainIdea(0, "Changed Original Dog Idea");
    std::cout << "Original Dog Brain Idea: " << originalDog.getBrainIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea: " << copiedDog.getBrainIdea(0) << std::endl;
    
    originalCat.setBrainIdea(0, "Changed Original Cat Idea");
    std::cout << "Original Cat Brain Idea: " << originalCat.getBrainIdea(0) << std::endl;
    std::cout << "Copied Cat Brain Idea: " << copiedCat.getBrainIdea(0) << std::endl;

    std::cout << std::endl;
    return (0);
}

