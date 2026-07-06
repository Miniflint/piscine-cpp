#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "Span.hpp"

int main(int ac, char **av)
{
	std::list<int>	vec;
	Span			t_vec(ac - 1);
	Span			t_one_one(10);
	if (ac < 2)
		return ((std::cout << "Not enough arguments" << std::endl), 1);
	if (ac > 100)
		return ((std::cout << "Not enough arguments" << std::endl), 1);
	for (int i = 1; i < ac; i++)
	{
		int j;
		std::stringstream buff(av[i]);
		buff >> j;
		if (buff.fail() || !buff || !buff.eof())
			std::cout << "Error on: " << av[1] << std::endl;
		std::cout << "Adding: " << av[i] << std::endl;
		vec.push_back(j);
		// will succeed all the time < 10 ac
		try {
			t_one_one.addNumber(j);
		} catch (Span::TooMuchIntegerException &e) {
			std::cout << "t_one_one: " << e.what() << std::endl;
		}
		// will succeed all the time after first add
		try {
			std::cout << "\tSmallest span: " << t_one_one.shortestSpan() << std::endl << "\tLongest span: " << t_one_one.longestSpan() << std::endl;
		} catch (Span::NoSpanException &e) {
			std::cout << "t_one_one: " << e.what() << std::endl;
			continue ;
		}
	}
	// will succeed all the time
	try {
		t_vec.addNumber(vec.begin(), vec.end());
	} catch (Span::TooMuchIntegerException &e) {
		std::cout << "t_vec: " << e.what() << std::endl;
	}
	// will fail all the time
	try {
		t_vec.addNumber(vec.begin(), vec.end());
	} catch (Span::TooMuchIntegerException &e) {
		std::cout << "t_vec: " << e.what() << std::endl;
	}
	// will succeed if ac > 2
	try {
		std::cout << "Smallest span: " << t_vec.shortestSpan() << std::endl << "Longest span: " << t_vec.longestSpan() << std::endl;
	} catch (Span::NoSpanException &e) {
		std::cout << "t_vec: " << e.what() << std::endl;
	}
	return (1);
}