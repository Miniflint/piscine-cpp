#include "../Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int	i;
	Zombie *zombieHordPtr;
	zombieHordPtr = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombieHordPtr[i].setName(name);	
		i++;
	}
	return (zombieHordPtr);
}
