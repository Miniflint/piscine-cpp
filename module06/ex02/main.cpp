#include "Base.hpp"

int main(void)
{
	srand(time(0));
	Base *which_base = generate();
	identify(which_base);
	identify(*which_base);
	delete which_base;
	return (0);
}