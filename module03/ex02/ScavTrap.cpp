#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardMode(false)
{
    this->_hitPoint = 100.0f;    
    this->_energyPoint = 50.0f;
    this->_attackPoint = 20.0f;
    std::cout << "ScavTrap constructor called with name: " << this->_name << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap(), _guardMode(false)
{
    this->_hitPoint = 100.0f;    
    this->_energyPoint = 50.0f;
    this->_attackPoint = 20.0f;
    std::cout << "ScavTrap constructor called nothing" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &trap) : ClapTrap(trap), _guardMode(false)
{
    std::cout << "ScavTrap constructor called with reference: " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called for: " << this->_name << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoint <= 0)
        std::cout << this->_name << " cannot attack, he's dead" << std::endl;
    if (this->_energyPoint <= 0)
        std::cout << this->_name << " cannot attack, no energy left" << std::endl;
    if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
        return ;
    this->_energyPoint -= 1;
    std::cout << "ScavTrap " << this->_name << " attacks [" << target << "], causing " << this->_attackPoint << " damage" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    this->_guardMode = true;
}