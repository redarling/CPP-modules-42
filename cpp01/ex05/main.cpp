#include "Harl.hpp"

int main(void)
{
    Harl    harl;

    harl.complain("WARNING");
    harl.complain("UNKNOWN");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("ERROR");
    harl.complain("UNKNOWN");

    return (0);
}