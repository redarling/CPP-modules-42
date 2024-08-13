#ifndef NOT_SIGNED_EXCEPTION_HPP
# define NOT_SIGNED_EXCEPTION_HPP

# include <exception>

class NotSignedException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif