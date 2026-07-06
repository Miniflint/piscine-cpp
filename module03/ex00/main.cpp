#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap t("test");

    t.attack("random");
    t.takeDamage(5);
    t.beRepaired(1);
    return (0);
}