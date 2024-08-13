#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
# define GRADE_TOO_LOW_EXCEPTION_HPP

# include <exception>

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
