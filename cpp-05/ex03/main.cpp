#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    ShrubberyCreationForm test;
    RobotomyRequestForm test2("LA TARGETE");
    PresidentialPardonForm pres("LA TARGETE");
    Bureaucrat peu_signer("Roi", 1);
    Bureaucrat peu_pas_signer("Sous homme", 150);
    Intern stagiaire;
    try
    {
        peu_signer.signForm(test);
        test.execute(peu_signer);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        test.beSigned(peu_pas_signer);
    }
    catch (std::exception &e)
    {
        std::cout << e.what()  << " to sign" << std::endl;
    }
    try
    {
        peu_signer.signForm(test2);
        test2.execute(peu_signer);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        peu_signer.signForm(pres);
        peu_signer.executeForm(pres);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        peu_pas_signer.signForm(test);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Form *tt = stagiaire.makeForm("robotomyerequest", "targete");
    Form *ttt = stagiaire.makeForm("robotomy request", "Bender");
    delete ttt;
    (void)tt;
    return (0);
}