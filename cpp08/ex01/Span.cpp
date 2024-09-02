#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(unsigned int size) : size(size) {}

Span::Span(const Span& other) : container(other.container), size(other.size) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->size = other.size;
        this->container = other.container;
    }
    return (*this);
}

void    Span::addNumber(int num)
{
    if (this->container.size() < this->size && this->size > 0)
        this->container.insert(num);
    else
        throw (SpanIsFull());
}

int     Span::shortestSpan()
{
    if (this->container.size() <= 1)
        throw (SpanNotPossible());

    std::multiset<int>::iterator    it = this->container.begin();
    std::multiset<int>::iterator    nextIt = it;
    int                             minSpan = INT_MAX;
    ++nextIt;

    while (nextIt != this->container.end())
    {
        int span = *nextIt - *it;
        if (span < minSpan)
            minSpan = span;
        ++it;
        ++nextIt;
    }

    return (minSpan);
}

int     Span::longestSpan()
{
    if (this->container.size() <= 1)
        throw (SpanNotPossible());
    
    int smallest = *this->container.begin();
    int largest = *this->container.rbegin();

    return (largest - smallest);
}