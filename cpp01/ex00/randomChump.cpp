#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie createZombie(name);
    createZombie.announce();
}