#include "SpanIsFull.hpp"

const char* SpanIsFull::what() const throw()
{
    return ("Operation isn't possible: Not enough free space!");
}