#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "Form.hpp"
#include <ctime>


class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    void    execute(Bureaucrat const &executor) const;
private:
    std::string target;
};

#endif