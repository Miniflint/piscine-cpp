#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &PresidentialPardonForm)
{
	(void)PresidentialPardonForm;
	std::cout << "stupid! (PresidentialPardonForm only has const and a value you shouldn't be allowed to assign)." << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  if (executor.getGrade() > this->getGradeExec())
      throw GradeTooLowException();
  if (!this->getSigned())
      throw NotSignedException();
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}