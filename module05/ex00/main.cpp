#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat test1 = Bureaucrat("test1", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
	try
	{
		Bureaucrat test2 = Bureaucrat("test2", -1);
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
	try
	{
		Bureaucrat test3 = Bureaucrat("test3", 2111111111);
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
	try
	{
		Bureaucrat test4 = Bureaucrat("test4", 1);
		std::cout << test4 << std::endl;
		test4.upGrade();
		std::cout << test4 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
	try
	{
		Bureaucrat test5 = Bureaucrat("test5", 150);
		std::cout << test5 << std::endl;
		test5.upGrade();
		std::cout << test5 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
	try
	{
		Bureaucrat test4 = Bureaucrat("test4", 1);
		std::cout << test4 << std::endl;
		test4.downGrade();
		std::cout << test4 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
	try
	{
		Bureaucrat test5 = Bureaucrat("test5", 150);
		std::cout << test5 << std::endl;
		test5.downGrade();
		std::cout << test5 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception catched in main." << std::endl;
	}
}