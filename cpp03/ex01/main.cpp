#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Andrii("Andrii");

    Andrii.attack("Bad guy");
    Andrii.beRepaired(20);
    Andrii.takeDamage(20);
    Andrii.takeDamage(20);
    Andrii.guardGate();

    ScavTrap CopyAndrii(Andrii);
    ScavTrap CopyCopyAndrii = CopyAndrii;
    CopyCopyAndrii.takeDamage(1000);

    return (0);
}