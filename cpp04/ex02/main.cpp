#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define MAX 10

int main(void)
{
	const Animal *animals[MAX];
    //const Animal animal = Animal(); // won't work

	for (int i = 0; i < MAX; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < MAX; i++)
		animals[i]->makeSound();

	for (int i = 0; i < MAX; i++)
		delete (animals[i]);

	return (0);
}

