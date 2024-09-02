#include "SpanNotPossible.hpp"

const char* SpanNotPossible::what() const throw()
{
    return ("Operation isn't possible: Not enough elements in the container!");
}