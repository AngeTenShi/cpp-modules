#ifndef MUTANTSTACK_HPP
#define MUTANTSTAKC_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(void) : std::stack<T>() {};
    MutantStack(MutantStack const &other) : std::stack<T>(other) {};
    MutantStack	&operator=(MutantStack const &other)
    {
        std::stack<T>::operator=(other);
        return (*this);
    }
    ~MutantStack(){}
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    iterator begin()
    {
        return (this->c.begin());
    }
    iterator end()
    {
        return (this->c.end());
    }
    const_iterator cbegin()
    {
        return (this->c.cbegin());
    }
    const_iterator cend()
    {
        return (this->c.cend());
    }
    reverse_iterator rbegin()
    {
        return (this->c.rbegin());
    }
    reverse_iterator rend()
    {
        return (this->c.rend());
    }
};

#endif
