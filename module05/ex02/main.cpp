#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <vector>
#include <bits/stdc++.h>
#include <time.h>

int main(void)
{
	srand(time(0));
	Bureaucrat 				AllExecute = Bureaucrat("AllExecute", 1);
	Bureaucrat 				MidExecute = Bureaucrat("MidExecute", 75);
	Bureaucrat 				NoExecute = Bureaucrat("NoExecute", 150);

	ShrubberyCreationForm	Shrubbery = ShrubberyCreationForm("2exec2sign");
	RobotomyRequestForm		Robotomy = RobotomyRequestForm("1exec2sign");
	PresidentialPardonForm	Presidential = PresidentialPardonForm("1exec1sign");


	std::vector<Bureaucrat*> vecB;
	vecB.push_back(&AllExecute); 
	vecB.push_back(&MidExecute); 
	vecB.push_back(&NoExecute);

	std::vector<AForm*> vecA;
	vecA.push_back(&Shrubbery); 
	vecA.push_back(&Robotomy); 
	vecA.push_back(&Presidential);

	std::vector<Bureaucrat*>::iterator itB;
	std::vector<AForm*>::iterator itA;

	for (itB = vecB.begin(); itB != vecB.end(); ++itB)
	{
		std::cout << "CURRENT Bureaucrat: " <<(**itB).getName() << std::endl;
		for (itA = vecA.begin(); itA != vecA.end(); ++itA)
		{
		std::cout << "\tCURRENT Form: " <<(**itA).getName() << std::endl;
			try
			{
				std::cout << "\t\t";
				(**itB).executeForm((**itA));
				std::cout << "\t\t";
				(**itA).beSigned((**itB));
				std::cout << "\t\t";
				(**itB).executeForm((**itA));
			}
			catch(const std::exception& e)
			{
				std::cerr << "Exception catched in the main" << std::endl;
			}
		}
	}
	
}