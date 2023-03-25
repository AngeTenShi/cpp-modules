#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

class Span
{
public:
    Span(unsigned int N);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();
    class TooManyValuesException : public std::exception
    {
        public :
            virtual const char *what() const throw()
            {
                return ("Too Many Values");
            }
    };
    class TooFewValuesException : public std::exception
    {
    public :
        virtual const char *what() const throw()
        {
            return ("Too Few Values");
        }
    };
    void    addNumber(unsigned int number);
    int     shortestSpan();
    int     longestSpan();
    std::vector<int> getVect() const;
    unsigned int getN() const;
    void 	addRangeNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
private:
    unsigned int _N;
    std::vector<int> vect;
};

#endif
