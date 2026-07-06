#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100.0f;
    this->_energyPoint = 100.0f;
    this->_attackPoint = 30.0f;
    std::cout << "FragTrap constructor called with name: " << this->_name << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap()
{
    this->_hitPoint = 100.0f;
    this->_energyPoint = 100.0f;
    this->_attackPoint = 30.0f;
    std::cout << "FragTrap constructor called nothing" << std::endl;
}

FragTrap::FragTrap(FragTrap const &trap) : ClapTrap(trap)
{
    std::cout << "FragTrap constructor called with reference: " << this->_name << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called for: " << this->_name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->_name << " is asking for a positive high-five request ?" << std::endl;
}
