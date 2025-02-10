#include "Zombie.hpp"

int main(void)
{
	int nb = 5;

	Zombie	*horde = zombieHorde(nb, "aa");
	while (--nb >= 0)
		horde[nb].announce();
	delete [] horde;
	return (0);
}