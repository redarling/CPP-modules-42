#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie firstZombie("Bob");
    firstZombie.announce();
    
    Zombie secondZombie("Mary Jane");
    secondZombie.announce();
    
    Zombie* heapZombie = newZombie("Sauron");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Bilbo");
}