#ifndef SPAN_NOT_POSSIBLE_HPP
# define SPAN_NOT_POSSIBLE_HPP

# include <exception>

class SpanNotPossible : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif