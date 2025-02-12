#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	HumanA	a("1", "wa");
	HumanB	b("2", "a");
	HumanB	b2("3");

	a.attack();
	b.attack();
	b2.attack();
	return (0);
}