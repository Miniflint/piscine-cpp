#include "Serializer.hpp"
# include <iostream>

int main(void)
{
	Data D1 = {1, 2};
	Data *D2 = Serializer::deserialize(Serializer::serialize(&D1));

	if (D2 != &D1)
	{
		std::cout << "D1: Values: " << D1.data1 << " | " << D1.data2 << std::endl;
		std::cout << "D2: Values: " << D2->data1 << " | " << D2->data2 << std::endl;
		std::cout << "D2 addr: " << D2 << "\nD1 addr: " << &D1 << std::endl;
		std::cout << "It doesn't work..." << std::endl;
	}
	else
	{
		std::cout << "D1: Values: " << D1.data1 << " | " << D1.data2 << std::endl;
		std::cout << "D2: Values: " << D2->data1 << " | " << D2->data2 << std::endl;
		std::cout << "D2 addr: " << D2 << "\nD1 addr: " << &D1 << std::endl;
		std::cout << "It works !!!" << std::endl;
	}
	return (0);
}