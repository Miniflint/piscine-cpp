#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "Span.hpp"

int main()
{
	Span test(8);
	std::list<int> t;
	
	t.push_back(100);
	t.push_back(-1000000000);
	t.push_back(-1000000001);
	
	
	try {test.longestSpan();} catch (Span::NoSpanException &e) { std::cout << e.what() << std::endl;}
	test.addNumber(1);
	test.addNumber(5);
	test.addNumber(35);
	test.addNumber(32);
	
	Span test_copy(test);
	
	test.addNumber(t.begin(), t.end());
	try {test.addNumber(t.begin(), t.end());} catch (Span::TooMuchIntegerException &e) { std::cout << e.what() << std::endl;}
	
	test.print_vector();
	std::cout << "smallest span: " << test.shortestSpan() << std::endl;
	std::cout << "longest span: " << test.longestSpan() << std::endl;
	test_copy.addNumber(2);
	test_copy.print_vector();
	std::cout << "smallest span: " << test_copy.shortestSpan() << std::endl;
	std::cout << "longest span: " << test_copy.longestSpan() << std::endl;
	
	Span test10000(200000);
	std::list<int> t2;
	for (int i = 200000;i > 0;--i)
	{
		if (i % 3)
			t2.push_front(i);
		else
			t2.push_back(i);
	}
	try {test10000.addNumber(t2.begin(), t2.end());} catch (Span::TooMuchIntegerException &e) { std::cout << e.what() << std::endl;}
	std::cout << "2 smallest span: " << test10000.shortestSpan() << std::endl;
	std::cout << "2 longest span: " << test10000.longestSpan() << std::endl;
	return (0);
}

// int main(int ac, char **av)
// {
// 	std::vector<int>	vec;
// 	Span			t_vec(ac - 1);
// 	Span			t_one_one(10);
// 	if (ac < 2)
// 		return ((std::cout << "Not enough arguments" << std::endl), 1);
// 	if (ac > 100)
// 		return ((std::cout << "Too many arguments" << std::endl), 1);
// 	for (int i = 1; i < ac; i++)
// 	{
// 		int j;
// 		std::stringstream buff(av[i]);
// 		buff >> j;
// 		if (buff.fail() || !buff || !buff.eof()) {
// 			std::cout << "Error on: " << av[1] << std::endl;
// 			continue ;
// 		}
// 		std::cout << "Adding: " << av[i] << std::endl;
// 		vec.push_back(j);
// 		// will succeed all the time < 10 ac
// 		try {
// 			t_one_one.addNumber(j);
// 		} catch (Span::TooMuchIntegerException &e) {
// 			std::cout << "t_one_one: " << e.what() << std::endl;
// 		}
// 		// will succeed all the time after first add
// 		try {
// 			std::cout << "\tSmallest span: " << t_one_one.shortestSpan() << std::endl << "\tLongest span: " << t_one_one.longestSpan() << std::endl;
// 		} catch (Span::NoSpanException &e) {
// 			std::cout << "t_one_one: " << e.what() << std::endl;
// 			continue ;
// 		}
// 	}
// 	// will succeed all the time
// 	try {
// 		t_vec.addNumber(vec.begin(), vec.end());
// 	} catch (Span::TooMuchIntegerException &e) {
// 		std::cout << "t_vec: " << e.what() << std::endl;
// 	}
// 	// will fail all the time
// 	try {
// 		t_vec.addNumber(vec.begin(), vec.end());
// 	} catch (Span::TooMuchIntegerException &e) {
// 		std::cout << "t_vec: " << e.what() << std::endl;
// 	}
// 	// will succeed if ac > 2
// 	try {
// 		std::cout << "Smallest span: " << t_vec.shortestSpan() << std::endl << "Longest span: " << t_vec.longestSpan() << std::endl;
// 	} catch (Span::NoSpanException &e) {
// 		std::cout << "t_vec: " << e.what() << std::endl;
// 	}
// 	return (0);
// }
