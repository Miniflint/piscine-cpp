#include <iostream>

int main(void)
{
	std::string	r = "HI THIS IS BRAIN";
	std::string	*stringPTR = &r;
	std::string	&stringREF = r;

	std::cout << "MEMORY ADDRESSES" << std::endl;
	std::cout << "\t str: " << &r << std::endl;
	std::cout << "\t ptr: " << stringPTR << std::endl;
	std::cout << "\t ref: " << &stringREF << std::endl;

	std::cout << "STRING" << std::endl;
	std::cout << "\t str: " << r << std::endl;
	std::cout << "\t ptr: " << *stringPTR << std::endl;
	std::cout << "\t ref: " << stringREF << std::endl;

	return (0);
}