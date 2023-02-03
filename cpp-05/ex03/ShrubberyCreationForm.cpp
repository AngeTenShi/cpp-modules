#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137), target("Default")
{
    std::cout << "Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), target(target)
{
    std::cout << "Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form("Shrubbery", 145, 137), target(other.target)
{
    std::cout << "Shrubbery Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    this->target = other.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->canExec(executor);
    std::string target = this->target + "_shrubbery";
    std::ofstream output(target.c_str());

    output << "      /\\\n"
              "     /**\\\n"
              "    /****\\\n"
              "   /******\\\n"
              "  /********\\\n"
              " /**********\\\n"
              "/************\\\n"
              "--------------\n";
    output.close();
}