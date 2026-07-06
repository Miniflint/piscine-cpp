#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &RobotomyRequestForm)
{
	(void)RobotomyRequestForm;
	std::cout << "stupid! (Robotomy only has const and a value you shouldn't be allowed to assign)." << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  if (executor.getGrade() > this->getGradeExec())
      throw GradeTooLowException();
  if (!this->getSigned())
      throw NotSignedException();
  if (rand() % 2)
    std::cout << "zzip zzap zzoup... " << this->_target << " was robotomised successfully !!!" << std::endl;
  else
    std::cout << "zzip zzap zzoup... " << this->_target << ", robotomysation failed miserably..." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}