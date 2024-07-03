#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap Monster("Monster");

    Monster.highFivesGuys();
    Monster.attack("Good guy");
    Monster.takeDamage(50);

    FragTrap Monster2 = Monster;
    Monster2.takeDamage(50);

    return (0);
}