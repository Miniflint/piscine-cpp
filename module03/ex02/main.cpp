#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap t("test");

    t.attack("random");
    t.takeDamage(49);
    t.takeDamage(49);
    t.takeDamage(49);
    t.beRepaired(1);
    return (0);
}