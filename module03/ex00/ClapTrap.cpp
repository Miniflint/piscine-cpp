#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    this->_hitPoint = 10.0f;
    this->_energyPoint = 10.0f;
    this->_attackPoint = 0.0f;
    std::cout << this->_name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << " has been destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    std::cout << this->_name << " attacks [" << target << "], causing " << this->_attackPoint << " damage" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->_energyPoint -= (float)amount;
    if (this->_energyPoint > 0.0f)
        std::cout << this->_name << " took " << amount << " of damage (" << this->_energyPoint << ")" << std::endl;
    else
        std::cout << this->_name << " died" << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    this->_energyPoint += (float)amount;
    std::cout << this->_name << " gained " << amount << " of life (" << this->_energyPoint << ")" << std::endl;
}