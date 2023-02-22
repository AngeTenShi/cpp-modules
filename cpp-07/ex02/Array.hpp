#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>

class Array
{
public:
    Array<T> (void) : elem(0), _size(0)
    {
        std::cout << "Constructor default called" << std::endl;
    };
    Array<T> (unsigned int n) : elem(new T[n]), _size(n)
    {
        std::cout << "Constructor n element called" << std::endl;
    };
    Array<T> (Array<T> const &other)
    {
        int i = 0;
        this->elem = new T[other.size()];
        while (i < other.size())
        {
            this->elem[i] = other.elem[i];
			i++;
        }
        this->_size = other.size();
    };
    ~Array<T> (void)
    {
        std::cout << "Destructor called" << std::endl;
        delete [] this->elem;
    }
    Array<T> &operator=(Array<T> const &other)
    {
        int i = 0;
        this->elem = new T[other.size()];
        while (i < other.size())
        {
            this->elem[i] = other.elem[i];
			i++;
        }
        this->_size = other.size();
        return (*this);
    };
    T   &operator[](int index)
    {
        if (index < 0 || index >= this->_size)
            throw (std::range_error("Index is out of range"));
        return(this->elem[index]);
    }
    int size() const {
        return (this->_size);
    };
private:
    T   *elem;
    int _size;
};


#endif