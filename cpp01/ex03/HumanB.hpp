#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(const std::string& set_name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon& set_weapon);

    private:
        std::string name;
        Weapon* his_weapon;
};

#endif
