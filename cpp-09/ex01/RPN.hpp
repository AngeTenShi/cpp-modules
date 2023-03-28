#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
    public:
        RPN(std::string expression);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void calculate();
    private:
        std::string expression;
        std::stack<float> stack;
        float result;
};