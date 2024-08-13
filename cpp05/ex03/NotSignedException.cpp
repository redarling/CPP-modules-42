#include "NotSignedException.hpp"

const char* NotSignedException::what() const throw()
{
    return ("This Form isn't signed yet!");
}
