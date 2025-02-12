#include "HumanB.hpp"

HumanB::HumanB(std::string name, std::string weapon_type) : HumanA(name, weapon_type)
{
	return ;
}

HumanB::HumanB(std::string name) : HumanA(name, "")
{
	return ;
}