#include <iostream>
#include <climits>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0 || N > INT_MAX)
    {
        std::cerr << "Error: Invalid number of zombies." << std::endl;
        return (nullptr);
    }
    
    if (name.empty())
    {
        std::cerr << "Error: Zombie name cannot be empty." << std::endl;
        return (nullptr);
    }

    Zombie* heapZombie = new Zombie[N];
    for (int i = 0; i < N; i++) 
    {
        heapZombie[i].hordeName(name);
    }
    return (heapZombie);
}
