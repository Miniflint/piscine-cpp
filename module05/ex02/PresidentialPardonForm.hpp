#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("default") {};
        PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {};
        ~PresidentialPardonForm() {};
        PresidentialPardonForm   &operator=(PresidentialPardonForm const &form);
        class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("PresidentialPardonForm: not signed exception.");
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