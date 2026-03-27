#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), _target("default") {};
        RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {};
        ~RobotomyRequestForm() {};
        RobotomyRequestForm   &operator=(RobotomyRequestForm const &form);
        class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("RobotomyRequestForm: not signed exception.");
				}
		};
        void	execute(Bureaucrat const & executor) const;

    };
    
    // class GradeTooHighException: public std::exception
    // {
    // 	public:
    // 		virtual const char* what() const throw()
    // 		{
    // 			return ("AForm: grade too high exception.");
    // 		}
    // };
    // class GradeTooLowException: public std::exception
    // {
    // 	public:
    // 		virtual const char* what() const throw()
    // 		{
    // 			return ("AForm: grade too low exception.");
    // 		}
    // };
    #endif