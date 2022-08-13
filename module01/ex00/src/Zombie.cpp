#include "../Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	announce();
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": \033[91m" << "died again" << "\033[0m" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": \033[92m" <<"BraiiiiiiinnnzzzZ..." << "\033[0m" << std::endl;
}
