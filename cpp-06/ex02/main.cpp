#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base    *generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return (new A);
    if (random == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base *p)
{
    A   *test1 = dynamic_cast<A *>(p);
    if (test1 != NULL)
    {
        std::cout << "This object is A" << std::endl;
        return ;
    }
    B   *test2 = dynamic_cast<B *>(p);
    if (test2 != NULL)
    {
        std::cout << "This object is B" << std::endl;
        return ;
    }
    C   *test3 = dynamic_cast<C *>(p);
    if (test3 != NULL)
    {
        std::cout << "This object is C" << std::endl;
        return ;
    }
}

void    identify(Base &p)
{
    try
    {
        A &test = dynamic_cast<A &>(p);
        (void)test;
        std::cout << "This object is A" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
        B &test = dynamic_cast<B &>(p);
        (void)test;
        std::cout << "This object is B" << std::endl;
    }
    catch (std::exception &e) {}
    try
    {
        C &test = dynamic_cast<C &>(p);
        (void)test;
        std::cout << "This object is C" << std::endl;
    }
    catch (std::exception &e) {}

}

int main(void)
{
    Base *generation;

    generation = generate();
    identify(generation);
    identify(*generation);

    delete generation;
    return (0);
}