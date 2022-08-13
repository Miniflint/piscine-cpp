#include "../Zombie.hpp"

void	randomChump (std::string name)
{
	Zombie *billieJeans;

	billieJeans = newZombie(name);
	delete billieJeans;
}
