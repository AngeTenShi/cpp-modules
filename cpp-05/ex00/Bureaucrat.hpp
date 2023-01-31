#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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