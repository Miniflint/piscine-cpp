#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB : public HumanA
{
	public:
		HumanB(std::string name, std::string);
		HumanB(std::string name);
};

#endif