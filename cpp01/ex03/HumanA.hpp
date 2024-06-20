#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string& set_name, Weapon& set_weapon);
        ~HumanA();
        void attack() const;

    private:
        std::string name;
        Weapon& his_weapon;
};

#endif
