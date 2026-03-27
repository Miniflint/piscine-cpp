#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern() {};
        Intern(const Intern &intern);
        ~Intern() {};
        Intern  operator=(const Intern &src);
        AForm   *makeForm(std::string whichForm, std::string whichTarget);
};

#endif