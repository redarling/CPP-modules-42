#ifndef SPAN_IS_FULL_HPP
# define SPAN_IS_FULL_HPP

#include <exception>

class SpanIsFull : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif