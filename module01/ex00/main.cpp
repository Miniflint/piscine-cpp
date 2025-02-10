#include "Zombie.hpp"

int main(void)
{
	Zombie	dies("NoAnnounce");
	Zombie	*zb = newZombie("newZombie");
	zb->announce();
	delete zb;
	return (0);
}