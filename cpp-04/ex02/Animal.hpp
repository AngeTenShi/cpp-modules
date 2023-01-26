#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
public:
    AAnimal();
    AAnimal(std::string name);
    AAnimal(const AAnimal &other);
    virtual ~AAnimal() = 0;
    virtual void    makeSound() const = 0;
    std::string getType() const;

protected:
    std::string type;
};

class Dog : public AAnimal
{
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void makeSound() const;
    std::string getType() const;
private:
    Brain *brain;
};

class Cat : public AAnimal
{
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void    makeSound() const;
    std::string getType() const;
private:
    Brain *brain;
};

#endif