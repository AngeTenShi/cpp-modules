#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 25, 5), target("Default")
{
    std::cout << "Presidential constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon", 25, 5), target(target)
{
    std::cout << "Presidential constructor with target called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form("PresidentialPardon", 25, 5), target(other.target)
{
    std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    this->target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential destructor constructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->canExec(executor);
    std::cout << this->target << " a été pardonné par Zaphod Beebleblrox" << std::endl;
}