#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat test1 = Bureaucrat("Btest1", 5);
	Bureaucrat test2 = Bureaucrat("Btest2", 50);
	Form		form1 = Form("Ftest1", 5, 5);
	Form		form2 = Form("Ftest2", 50, 50);

	test2.signForm(form1); // pas réussir (to low)
	test2.signForm(form2); // réussir
	test1.signForm(form1); // réussir
	test1.signForm(form2); // pas réussir (already signed)
	try
	{
		Form		form3 = Form("test2", 500, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		form3 = Form("test2", 50, 350);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}