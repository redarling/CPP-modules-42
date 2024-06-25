#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& set_name) : name(set_name), his_weapon(nullptr)
{
}

HumanB::~HumanB()
{
    std::cout << this->name << ": gone into the sunset.." << std::endl;
}

void HumanB::attack() const
{
    if (this->his_weapon)
    {
        std::cout << this->name << ": attacks with their " 
                  << this->his_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->name << " doesn't know kung fu to attack without a weapon"
                  << std::endl;
    }
}

void HumanB::setWeapon(Weapon& set_weapon)
{
    this->his_weapon = &set_weapon;
}
