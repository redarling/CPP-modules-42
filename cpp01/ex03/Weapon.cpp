#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& new_type) : type(new_type)
{
}

Weapon::~Weapon()
{
    std::cout << this->type << ": dropped" << std::endl;
}

void Weapon::setType(const std::string& new_type)
{
    this->type = new_type;
}

const std::string& Weapon::getType() const
{
    return this->type;
}
