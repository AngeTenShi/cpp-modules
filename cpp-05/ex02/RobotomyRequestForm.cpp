#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45), target("Default")
{
    std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form("Robotomy", 72, 45), target(other.target)
{
    std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45)
{
    this->target = target;
    std::cout << "Robotomy constructor with target called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    this->target = other.target;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    this->canExec(executor);
    std::srand(time(NULL));
    int proba = rand();
    std::cout << "vrrrrrrrrrr brrrrrrrrrr (perceuse)" << std::endl;
    if (proba % 2 == 0)
        std::cout << this->target << " a été robotomisé avec succès" << std::endl;
    else
        std::cout << this->target << " n'a pas été robotomisé" << std::endl;
}