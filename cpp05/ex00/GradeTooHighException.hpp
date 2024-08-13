// GradeTooHighException.hpp
#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
# define GRADE_TOO_HIGH_EXCEPTION_HPP

# include <exception>

class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
