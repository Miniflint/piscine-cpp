#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_wp;

	public:
		HumanB(std::string name, Weapon *weapon_type);
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &new_weapon);
		void	attack(void) const;
};

#endif