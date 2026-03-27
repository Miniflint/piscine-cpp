#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form const &Form);
		~Form();
		Form &operator=(Form const &Form);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: grade too high exception.");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: grade too low exception.");
				}
		};
		std::string getName() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
		bool	getSigned() const;
		void 	beSigned(Bureaucrat &signant);
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif
