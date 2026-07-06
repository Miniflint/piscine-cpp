#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
	protected:
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm() : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150) {};
	public:
		virtual ~AForm() = 0;
		AForm(AForm const &AForm);
		AForm &operator=(AForm const &AForm);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm: grade too high exception.");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("AForm: grade too low exception.");
				}
		};
		std::string 	getName() const;
		int				getGradeSign() const;
		int				getGradeExec() const;
		bool			getSigned() const;
		void 			beSigned(const Bureaucrat &signant);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
