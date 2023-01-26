#include "Animal.hpp"


int main(void)
{
 //   Animal *tab[4];


    Dog test;
    Dog test2(test); // test for deep copy brain 2 differents brain
    for (int i = 0; i < 2; i++)
    {
        tab[i] = new Dog();
    }

    for (int i = 2; i < 4; i++)
    {
        tab[i] = new Cat();
    }

    for (int i = 0; i < 4; i++)
    {
        delete tab[i];
    }
}