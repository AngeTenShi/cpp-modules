#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const WrongAnimal *metaa = new WrongAnimal();
    const WrongAnimal *ii = new WrongCat();
    const Animal *meta = new Animal();
    const Animal *i = new Cat();
    const Animal *j = new Dog();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << ii->getType() << " " << std::endl;
    std::cout << metaa->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    ii->makeSound();
    metaa->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete ii;
    delete metaa;

    return (0);
}