#include "Form.hpp"

Form::Form() : name("noname"), marked(false), gradeToMark(150), gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToMark, int gradeToExecute) : name(name), marked(false), gradeToMark(gradeToMark), gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;
    if (gradeToMark <= 0 || gradeToExecute <= 0)
        throw (Form::GradeTooHighException());
    if (gradeToMark > 150 || gradeToExecute > 150)
        throw(Form::GradeTooLowException());
}


Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
    return ;
}

Form::Form(const Form &other) : name(other.name), marked(other.marked), gradeToMark(other.gradeToMark), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    this->marked = other.marked;
    return (*this);
}

void Form::beSigned(Bureaucrat const &other)
{
    if (other.getGrade() <= this->gradeToMark)
        this->marked = true;
    else
        throw (Form::GradeTooLowException());
}

std::string Form::getName() const
{
    return (this->name);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

int Form::getGradeToMark() const
{
    return (this->gradeToMark);
}

bool Form::getMarked() const
{
    return (this->marked);
}

void Form::canExec(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeToExecute)
        throw (Bureaucrat::GradeTooLowException());
    if (this->marked == false)
        throw (Form::FormNotSignException());
}

std::ostream &operator<<(std::ostream &stream, Form const &toprint)
{
    stream << "Form name : "<< toprint.getName() << " Grade to execute : " << toprint.getGradeToExecute() << " Grade to mark : "<< toprint.getGradeToMark() << " Is marked : " << toprint.getMarked();
    return (stream);
}