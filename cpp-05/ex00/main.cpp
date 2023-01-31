#include "Bureaucrat.hpp"

int main(void)
{

    try
    {
        Bureaucrat bureaucrat("nom", 0);
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