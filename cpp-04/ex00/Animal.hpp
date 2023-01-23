#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal();
    virtual void    makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void makeSound() const;
    std::string getType() const;
};

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void    makeSound() const;
    std::string getType() const;
};

#endif