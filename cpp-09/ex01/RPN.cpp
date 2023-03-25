#include "RPN.hpp"

RPN::RPN(std::string expression)
{
    this->result = 0;
    this->expression = expression;
    return ;
}

RPN::RPN(const RPN &other)
{
    this->result = other.result;
    this->expression = other.expression;
    return ;
}

RPN &RPN::operator=(const RPN &other)
{
    this->result = other.result;
    this->expression = other.expression;
    return (*this);
}

RPN::~RPN()
{
    return ;
}

void RPN::calculate()
{
    while (this->expression.find(' ') != std::string::npos)
        this->expression.erase(this->expression.find(' '), 1);
    std::string::iterator it = this->expression.begin();
    std::string::iterator ite = this->expression.end();
    while (it != ite)
    {
        if (!isdigit(*it) && (*it != '+' && *it != '-' && *it != '*' && *it != '/'))
        {
            std::cout << "Error" << std::endl;
            return ;
        }
        if (isdigit(*it))
            this->stack.push(*it);
        if (*it == '+')
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            this->result = this->stack.top() - '0';
            this->stack.pop();
            this->result += this->stack.top() - '0';
            this->stack.pop();
            this->stack.push(this->result + '0');
        }
        if (*it == '-')
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            this->result = this->stack.top() - '0';
            this->stack.pop();
            this->result = this->stack.top() - '0' - this->result;
            this->stack.pop();
            this->stack.push(this->result + '0');
        }
        if (*it == '*')
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            this->result = this->stack.top() - '0';
            this->stack.pop();
            this->result *= this->stack.top() - '0';
            this->stack.pop();
            this->stack.push(this->result + '0');
        }
        if (*it == '/')
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            this->result = this->stack.top() - '0';
            this->stack.pop();
            this->result /= (this->stack.top() - '0');
            this->stack.pop();
            this->stack.push(this->result + '0');
        }
        it++;
    }
    std::cout << this->stack.top() - '0' << std::endl;
    return ;
}