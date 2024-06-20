#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
    public:
        Weapon(const std::string& new_type);
        ~Weapon();
        void setType(const std::string& new_type);
        const std::string& getType() const;

    private:
        std::string type;
};

#endif
