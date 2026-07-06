#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget()) {};
        ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("default") {};
        ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) {};
        ~ShrubberyCreationForm() {};
        ShrubberyCreationForm   &operator=(ShrubberyCreationForm const &form);
        class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("ShrubberyCreationForm: not signed exception.");
				}
		};
        void	execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
};

#endif