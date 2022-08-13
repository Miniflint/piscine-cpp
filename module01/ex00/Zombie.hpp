#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define log(x) std::cout << x << std::endl


class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce (void);
};

Zombie *newZombie (std::string name);
void randomChump (std::string name);

#endif
