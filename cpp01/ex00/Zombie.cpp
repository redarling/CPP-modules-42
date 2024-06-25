#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(const std::string& name)  : _name(name)
{
}

Zombie::~Zombie()
{
    if (! _name.empty())
    {
        std::cout << this->_name << ": destroyed" << std::endl;
    }
}


void Zombie::announce(void) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}