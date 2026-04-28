#include "easyfind.hpp"
#include <vector>

#include <iostream>

int main()
{
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(4);
	std::cout << "9: " << (easyfind(vec, 9) ? "true" : "false")  << std::endl;
	std::cout << "5: "<< (easyfind(vec, 5) ? "true" : "false")  << std::endl;
	std::cout << "a(97): "<< (easyfind(vec, 'a') ? "true" : "false")  << std::endl;
	vec.push_back('a');
	std::cout << "a(97): "<< (easyfind(vec, 'a') ? "true" : "false")  << std::endl;
	return (0);
}