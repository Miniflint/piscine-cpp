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
        Intern(__attribute_maybe_unused__ const Intern &intern) {};
        ~Intern() {};
        Intern  operator=(__attribute_maybe_unused__ const Intern &src);
        AForm   *makeForm(std::string whichForm, std::string whichTarget);
};

#endif