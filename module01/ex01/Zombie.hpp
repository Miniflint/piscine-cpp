#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define log(x) std::cout << x << std::endl


class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie(void);
		void setName (std::string name);
		void announce (void);
		void zombieName(std::string name);
};

Zombie *zombieHorde (int N, std::string name);
#endif
