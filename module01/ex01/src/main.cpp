#include "../Zombie.hpp"

int	main()
{
	Zombie *horde;
	horde = zombieHorde(10, "hehe");

	std::cout << "========" << std::endl;
	delete[] horde;
	return (0);
}
