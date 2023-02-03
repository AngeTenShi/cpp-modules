#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void    incrementGrade();
    void    decrementGrade();
    void    signForm(Form &other);
    void    executeForm(Form const &form);
    class GradeTooHighException : public std::exception
    {
    public :
        virtual const char *what() const throw()
        {
            return ("Grade is too high");
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Grade is too low");
        }

    };
private:
    std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &toprint);

#endif