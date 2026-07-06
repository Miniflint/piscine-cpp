#include <vector>

#include <iostream>
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
	
	test.print_list();
	std::cout << "smallest span: " << test.shortestSpan() << std::endl;
	std::cout << "longest span: " << test.longestSpan() << std::endl;
	test_copy.addNumber(2);
	test_copy.print_list();
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
