#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void printElement(T& elem)
{
    std::cout << elem << std::endl;
}

template <typename T>
void		capitalizer(T& elem, unsigned int len)
{
    for(unsigned int i = 0; i < len; i++)
	{
        if (elem[i] >= 'a' && elem[i] <= 'z')
		    elem[i] -= 32;
    }
}

template <typename T>
void iter(T* array, unsigned int len, void (*f)(T&))
{
    if (array == NULL || f == NULL)
		return ;
    for(unsigned int i = 0; i < len; i++)
        f(array[i]);
}

#endif
