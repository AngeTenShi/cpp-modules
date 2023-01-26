#include "Animal.hpp"


int main(void)
{
    AAnimal *tab[4];

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