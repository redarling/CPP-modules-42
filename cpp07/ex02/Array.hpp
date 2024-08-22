#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <class T>
class Array
{
    private:
        T*              _arr;
        unsigned int    _arraySize;

    public:
        Array();
        Array(unsigned int s);
        Array(const Array& other);
        ~Array();
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        unsigned int size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Index is out of bounds";
                }
        };
};

template <class T>
Array<T>::Array() : _arr(NULL), _arraySize(0) {}

template <class T>
Array<T>::Array(unsigned int s) : _arraySize(s)
{
    if (this->_arraySize != 0)
        this->_arr = new T[this->_arraySize]();
    else
        this->_arr = NULL;
}

template <class T>
Array<T>::Array(const Array& other) : _arraySize(other.size())
{
    if (this->_arraySize != 0)
    {
        this->_arr = new T[this->_arraySize];
        for (unsigned int i = 0; i < this->_arraySize; ++i)
            this->_arr[i] = other._arr[i];
        }
    else
        this->_arr = NULL;
}

template <class T>
Array<T>::~Array()
{
    if (this->_arraySize != 0)
        delete[] (this->_arr);
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        if (this->_arraySize != 0)
            delete[] (this->_arr);
        this->_arraySize = other.size();
    if (this->_arraySize != 0)
    {
        this->_arr = new T[this->_arraySize];
        for (unsigned int i = 0; i < this->_arraySize; ++i)
        {
            this->_arr[i] = other._arr[i];
        }
    }
    else
        this->_arr = NULL;
    }
    return (*this);
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_arraySize)
        throw (OutOfBoundsException());
    return (this->_arr[index]);
}

template <class T>
unsigned int Array<T>::size() const
{
    return (this->_arraySize);
}

#endif