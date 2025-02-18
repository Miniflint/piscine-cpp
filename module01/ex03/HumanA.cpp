#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_type) : _name(name), _wp(weapon_type)
{
    return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void    HumanA::setWeapon(Weapon &new_weapon)
{
    this->_wp = new_weapon;
}

void	HumanA::attack() const
{
	std::cout << this->_name << ": attacks with " << this->_wp.getType() << std::endl;
	return ;
}
