#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon_type) : _name(name), _wp(weapon_type)
{
    return ;
}

HumanB::HumanB(std::string name) : _name(name), _wp(NULL)
{
    return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void    HumanB::setWeapon(Weapon &new_weapon)
{
    this->_wp = &new_weapon;
}

void	HumanB::attack() const
{
	std::cout << this->_name << ": attacks with " << (*this->_wp).getType() << std::endl;
	return ;
}
