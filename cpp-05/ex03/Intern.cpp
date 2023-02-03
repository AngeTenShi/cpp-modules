#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
    (void)other;
    std::cout << "Intern default constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Form *makeShrubberyCreation(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form *makePresidentialPardon(std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form *makeRobotomyRequest(std::string target)
{
    return (new RobotomyRequestForm(target));
}


Form *Intern::makeForm(std::string name, std::string target)
{
    Form    *ret;
    bool    found;
    std::string names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    typedef Form *(*makeFormulaire)(std::string target);
    makeFormulaire forms[3] = {makePresidentialPardon, makeRobotomyRequest, makeShrubberyCreation};
    for (int i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            ret = forms[i](target);
            std::cout << "Intern creates " << name << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "Intern can't create this form because it doesn't exist" << std::endl;
    return (ret);
}