#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

    Form formulaire("Contrat avec dieu", 110, 1);
    Bureaucrat a("pas assez gradé", 120);
    std::cout << formulaire << std::endl;
    a.signForm(formulaire);
    std::cout << formulaire << std::endl;
    try
    {
        Bureaucrat bureaucrat("nom", 1);
        bureaucrat.signForm(formulaire);
        bureaucrat.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "*** " << e.what() << " ***" << std::endl;
    }
    try
    {
        Bureaucrat bur("toolow", -2);
        std::cout << bur << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "*** " << e.what() << " ***" << std::endl;
    }
    try
    {
        Bureaucrat bur2("toohigh", 151);
        std::cout << bur2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "*** " << e.what() << " ***" << std::endl;
    }

    return (0);
}