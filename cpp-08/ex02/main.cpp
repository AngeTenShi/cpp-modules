#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    MutantStack<int> m2stack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    std::cout << *it << std::endl;
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    m2stack.push(5);
    m2stack.pop();
    m2stack.push(4);
    m2stack.push(3);
    m2stack.push(2);
    m2stack.push(1);
    MutantStack<int>::reverse_iterator it2 = m2stack.rbegin();
    MutantStack<int>::reverse_iterator ite2 = m2stack.rend();
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    return (0);
}