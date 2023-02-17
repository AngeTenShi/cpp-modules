#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->_N = N;
}

Span::~Span()
{
    return ;
}

Span::Span(const Span &other)
{
    *this = other;
}

unsigned int Span::getN() const
{
    return (this->_N);
}

std::vector<int> Span::getVect() const
{
    return (this->vect);
}

Span &Span::operator=(Span const &other)
{
    this->_N = other.getN();
    this->vect = other.getVect();
    return (*this);
}


void Span::addNumber(unsigned int number)
{
    if (this->vect.size() >= this->_N)
        throw Span::TooManyValuesException();
    this->vect.push_back(number);
}

int Span::shortestSpan()
{
    if (this->vect.size() <= 1)
        throw Span::TooFewValuesException();
    std::sort(this->vect.begin(), this->vect.end());
    int minDiff = this->vect[1] - this->vect[0];
    for (long unsigned int i = 2; i < this->vect.size(); i++)
    {
        int diff = this->vect[i] - this->vect[i-1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return (minDiff);
}

int Span::longestSpan()
{
    if (this->vect.size() <= 1)
        throw Span::TooFewValuesException();
    return (*max_element(this->vect.begin(), this->vect.end()) - *min_element(this->vect.begin(), this->vect.end()));
}

void 	Span::addRangeNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    //if (std::distance(begin, end) > this->_N)
    //    throw Span::TooManyValuesException();
    this->vect.assign(begin, end);
}