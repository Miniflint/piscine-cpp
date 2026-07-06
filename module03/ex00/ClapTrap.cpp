#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoint(10.0f), _energyPoint(10.0f), _attackPoint(0.0f)
{
    std::cout << "constructor has been called with no name" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10.0f), _energyPoint(10.0f), _attackPoint(0.0f)
{
    std::cout << "constructor has been called with name: " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &trap): _name(trap.getName()), _hitPoint(10.0f), _energyPoint(10.0f), _attackPoint(0.0f)
{
    std::cout << "constructor called with reference: " << this->_name << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoint <= 0)
        std::cout << this->_name << " cannot attack, he's dead" << std::endl;
    if (this->_energyPoint <= 0)
        std::cout << this->_name << " cannot attack, no energy left" << std::endl;
    if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
        return ;
    this->_energyPoint -= 1;
    std::cout << this->_name << " attacks [" << target << "], causing " << this->_attackPoint << " damage" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoint -= (float)amount;
    if (this->_hitPoint > 0.0f)
        std::cout << this->_name << " took " << amount << " of damage (" << this->_hitPoint << ")" << std::endl;
    else
        std::cout << this->_name << " died" << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoint <= 0)
        std::cout << this->_name << " cannot repair, he's dead" << std::endl;
    if (this->_energyPoint <= 0)
        std::cout << this->_name << " cannot repair, no energy left" << std::endl;
    if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
        return ;
    this->_energyPoint -= 1;
    this->_hitPoint += (float)amount;
    std::cout << this->_name << " gained " << amount << " of life (" << this->_hitPoint << ")" << std::endl;
}