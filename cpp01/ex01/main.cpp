#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie* horde = zombieHorde(5, "Orc");
    Zombie* horde2 = zombieHorde(-1, "FakeOrc");
    if (horde)
    {
        for (int i = 0; i < 5; i++)
        {
            horde[i].announce();
        }
        /*for (int i = 0; i < N; i++)
        {
            horde[i].~Zombie();
        }*/
        delete[] horde;
    }
    if (horde2)
    {
        for (int i = 0; i < 5; i++)
        {
            horde[i].announce();
        }
        /*for (int i = 0; i < N; i++)
        {
            horde[i].~Zombie();
        }*/
        delete[] horde;
    }
    return (0);
}