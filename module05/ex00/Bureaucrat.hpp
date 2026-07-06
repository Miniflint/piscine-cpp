#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat() : _name("default"), _grade(150) {};
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &bureaucrat);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Bureaucrat: grade too high exception.");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Bureaucrat: grade too low exception.");
				}
		};
		void	upGrade();
		void	downGrade();
		std::string getName() const;
		int getGrade() const;
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
