#include "GradeTooLowException.hpp"

const char* GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}
