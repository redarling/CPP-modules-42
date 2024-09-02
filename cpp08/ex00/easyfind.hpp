#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator  it;
    
    it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw (std::runtime_error("Value not found"));
    
    return (it);
}

#endif
