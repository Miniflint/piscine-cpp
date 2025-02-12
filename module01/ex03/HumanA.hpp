#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		wp;

	public:
		HumanA(std::string name, std::string weapon_type);
		~HumanA(void);
		void	attack(void);
};

#endif