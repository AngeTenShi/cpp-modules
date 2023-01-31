#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form();
    Form(std::string name, int gradeToMark, int gradeToExecute);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();
    void    beSigned(Bureaucrat &other);
    std::string    getName() const;
    bool        getMarked() const;
    int         getGradeToMark() const;
    int         getGradeToExecute() const;
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
    const std::string name;
    bool marked;
    const int  gradeToMark;
    const int  gradeToExecute;
};

std::ostream &operator<<(std::ostream &stream, Form const &toprint);

#endif