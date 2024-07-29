#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Jack("Jack Sparrow");
    std::cout << std::endl;
	Jack.whoAmI();
    std::cout << std::endl;
	Jack.attack("Davy Jones");
    std::cout << std::endl;
    Jack.takeDamage(30);
    std::cout << std::endl;
    Jack.beRepaired(100);
    std::cout << std::endl;
	return (0);
}