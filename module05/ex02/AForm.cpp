#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _signed(0), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "AForm is has been created by normal init" << std::endl;
	try
	{
		if (this->_gradeSign > 150 || this->_gradeExec > 150)
			throw AForm::GradeTooLowException();
		else if (this->_gradeSign < 1 || this->_gradeExec < 1)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}

}

AForm::AForm(AForm const &AForm) : _name(AForm.getName()), _signed(0), _gradeSign(AForm.getGradeSign()), _gradeExec(AForm.getGradeExec())
{
	std::cout << "AForm copy constructor called" << std::endl;
	try
	{
		if (this->_gradeSign > 150 || this->_gradeExec > 150)
			throw AForm::GradeTooLowException();
		else if (this->_gradeSign < 1 || this->_gradeExec < 1)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

void AForm::beSigned(Bureaucrat &signant)
{
	try
	{
		if (signant.getGrade() > this->_gradeSign)
			throw AForm::GradeTooLowException();
		else
		{
			std::cout << signant.getName() << " signed " << this->getName() << std::endl;
			this->_signed = 1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw ;
	}
	
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int	AForm::getGradeExec() const
{
	return this->_gradeExec;
}

AForm &AForm::operator=(AForm const &AForm)
{
	(void)AForm;
	std::cout << "stupid! (AForm only has const and a value you shouldn't be allowed to assign)." << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& b) {
	return os << b.getName() << ", AForm sign grade " << b.getGradeSign() << ", AForm exec grade " << b.getGradeExec() << ".";
}