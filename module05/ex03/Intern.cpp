#include "Intern.hpp"

Intern::Intern(const Intern &intern) {
    (void)intern;
}

Intern Intern::operator=(const Intern &src)
{
    (void)src;
    return *this; 
}

std::string lower(std::string s)
{
    std::string ret;
    for (std::string::iterator it = s.begin(); it < s.end(); ++it)
    {
        ret.push_back(*it >= 'A' && *it <= 'Z' ? *it + 32 : *it);
    }
    return ret;
};

AForm * shrubberyCreate(std::string target)
{
    return new ShrubberyCreationForm(target);

}

AForm * robotomyCreate(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm * presidentialCreate(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm   *Intern::makeForm(std::string whichForm, std::string whichTarget)
{
    whichForm = lower(whichForm);
    static const std::string names[2][3] = {
        {"shrubbery creation", "robotomy request", "presidential pardon"},
        {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"},
    };
    static AForm* (*formCreation[3])(std::string) = {shrubberyCreate, robotomyCreate, presidentialCreate};
    for (size_t i = 0; i < 3; i++)
    {
        if (whichForm == names[0][i])
        {
            std::cout << "Intern creates " << names[1][i] << std::endl;
            return (formCreation[i](whichTarget));
        }
    }
    std::cout << "Intern cannot create " << whichForm << std::endl;
    return (NULL);
}
