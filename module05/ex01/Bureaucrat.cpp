#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat named: " << this->_name << " with grade: " << this->_grade << " default constructor called" << std::endl;
	try
	{
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	try
	{
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &bureaucrat)
	{
		this->_grade = bureaucrat.getGrade();
		try
		{
			if (this->_grade > 150)
				throw Bureaucrat::GradeTooLowException();
			else if (this->_grade < 1)
				throw Bureaucrat::GradeTooHighException();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			throw;
		}
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::upGrade()
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			--this->_grade;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}

}

void	Bureaucrat::downGrade()
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			++this->_grade;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw ;
	}
}

void	Bureaucrat::signForm(Form &f) const
{
	try
	{
		if (f.getSigned())
		{
			std::cout << this->getName() << " couldn’t sign " << f.getName() << " because it is already signed." << std::endl;
		}
		else
		{
			f.beSigned(*this);
			std::cout << this->_name << " signed " << f.getName() << std::endl;
		}
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn’t sign " << f.getName() << " because the bureaucrat grade is to low." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
