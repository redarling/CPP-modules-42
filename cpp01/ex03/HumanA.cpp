#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& set_name, Weapon& set_weapon) : name(set_name), his_weapon(set_weapon)
{
}

HumanA::~HumanA()
{
    std::cout << this->name << " gone into the sunset.." << std::endl;
}

void HumanA::attack() const
{
    std::cout << this->name << ": attacks with their " 
        << his_weapon.getType() << std::endl;
}
  