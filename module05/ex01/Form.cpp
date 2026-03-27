#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _signed(0), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Form is has been created by normal init" << std::endl;
	try
	{
		if (this->_gradeSign > 150 || this->_gradeExec > 150)
			throw Form::GradeTooLowException();
		else if (this->_gradeSign < 1 || this->_gradeExec < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}

}

Form::Form(Form const &Form) : _name(Form.getName()), _signed(0), _gradeSign(Form.getGradeSign()), _gradeExec(Form.getGradeExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	try
	{
		if (this->_gradeSign > 150 || this->_gradeExec > 150)
			throw Form::GradeTooLowException();
		else if (this->_gradeSign < 1 || this->_gradeExec < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

void Form::beSigned(const Bureaucrat &signant)
{
	try
	{
		if (signant.getGrade() > this->_gradeSign)
			throw Form::GradeTooLowException();
		else
			this->_signed = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw ;
	}
	
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int	Form::getGradeSign() const
{
	return this->_gradeSign;
}

int	Form::getGradeExec() const
{
	return this->_gradeExec;
}

Form &Form::operator=(Form const &Form)
{
	(void)Form;
	std::cout << "stupid! (form only has const and a value you shouldn't be allowed to assign)." << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& b) {
	return os << b.getName() << ", Form sign grade " << b.getGradeSign() << ", Form exec grade " << b.getGradeExec() << ".";
}