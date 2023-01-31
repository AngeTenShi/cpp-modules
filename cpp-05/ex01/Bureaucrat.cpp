#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    this->name = "noname";
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    this->name = name;
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
    return ;
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    this->name = other.name;
    this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->name = other.name;
    this->grade = other.grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &toprint)
{
    stream << toprint.getName() << ", bureaucrat grade " << toprint.getGrade();
    return (stream);
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw (Bureaucrat::GradeTooLowException());
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw (Bureaucrat::GradeTooHighException());
    this->grade++;
}

void Bureaucrat::signForm(Form &other)
{
    try
    {
        other.beSigned(*this);
        std::cout << this->name << " signed " << other.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << other.getName() << " because "  << e.what() << std::endl;
    }
}