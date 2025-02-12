#include "HumanA.hpp"

HumanA::HumanA(std::string name, std::string weapon_type)
{
	this->_name = name;
	this->wp.setType(weapon_type);
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack()
{
	if (this->wp.getType()[0])
		std::cout << this->_name << ": attacks with " << this->wp.getType() << std::endl;
	else
		std::cout << this->_name << ": has no weapon to attack :( "<< std::endl;
	return ;
}

