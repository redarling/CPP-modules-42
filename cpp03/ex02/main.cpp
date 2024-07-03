#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap Monster("Monster");

    Monster.highFivesGuys();
    Monster.attack("Good guy");
    Monster.takeDamage(50);
    Monster.beRepaired(0);
    Monster.takeDamage(49);

    FragTrap Monster2 = Monster;
    Monster2.takeDamage(1);

    return (0);
}