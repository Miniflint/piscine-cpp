#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap t("test");

    t.attack("random");
    t.takeDamage(5);
    t.beRepaired(1);
    return (0);
}