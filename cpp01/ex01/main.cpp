#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie* horde = zombieHorde(5, "Orc");
    Zombie* horde2 = zombieHorde(-1, "FakeOrc");
    
    if (horde)
    {
        for (int i = 0; i < 5; i++)
            horde[i].announce();
        delete[] horde;
    }
    else
        std::cerr << "Failed to create zombie horde." << std::endl;
    
    if (horde2)
    {
        for (int i = 0; i < 5; i++)
            horde2[i].announce();
        delete[] horde2;
    }
    else
        std::cerr << "Failed to create zombie horde." << std::endl;

    return (0);
}
