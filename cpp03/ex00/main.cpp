#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Sauron("Sauron");

    Sauron.takeDamage(10);
    Sauron.attack("Bilbo");
    Sauron.beRepaired(15);
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.takeDamage(100);
    Sauron.attack("Bilbo");
    Sauron.beRepaired(1000);
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.attack("Bilbo");
    Sauron.beRepaired(1000);

    ClapTrap Sauron2(Sauron);
    Sauron2.attack("Bilbo");

    ClapTrap Frodo("Frodo");
    Frodo.attack("Sauron");
    Frodo = Sauron2;
    Frodo.attack("Sauron");

    return (0);
}