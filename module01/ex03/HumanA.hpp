#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_wp;

	public:
		HumanA(std::string name, Weapon &weapon_type);
		~HumanA(void);
        void    setWeapon(Weapon &new_weapon);
		void	attack(void) const;
};

#endif