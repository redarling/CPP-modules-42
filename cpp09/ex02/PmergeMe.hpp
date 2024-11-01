#pragma once

#include <iostream>
#include <algorithm>

enum printMsg
{
    BEFORE,
    AFTER
};

template <class T>
class PmergeMe
{
    private:
        T  _container;

        void        insertWithBinarySearch(T& sorted, const T& elementsToInsert);
        void        recursiveMergeSort(const T& input, T& output);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        PmergeMe&   operator=(const PmergeMe& other);

        void        fillContainer(int argc, char **argv);
        void        printContainer(printMsg msg);
        void        mergeInsertionSort();
};

template <typename T>
PmergeMe<T>::PmergeMe() : _container() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other) : _container(other._container) {}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>&    PmergeMe<T>::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_container.clear();
        this->_container = other._container;
    }

    return (*this);
}

template <typename T>
void PmergeMe<T>::printContainer(printMsg msg)
{
    if (this->_container.empty())
    {
        std::cout << "Container is empty" << std::endl;
        return;
    }

    std::cout << (msg == BEFORE ? "Before: " : "After: ");

    for (typename T::iterator it = this->_container.begin(); it != this->_container.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void    PmergeMe<T>::fillContainer(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        long long num = std::atoll(argv[i]);
        this->_container.push_back(static_cast<int>(num));
    }
}

template <typename T>
void PmergeMe<T>::insertWithBinarySearch(T& sorted, const T& elementsToInsert)
{
    for (typename T::const_iterator it = elementsToInsert.begin(); it != elementsToInsert.end(); ++it)
    {
        typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
        sorted.insert(pos, *it);
    }
}

template <typename T>
void PmergeMe<T>::recursiveMergeSort(const T& input, T& output)
{
    if (input.size() <= 1)
    {
        output = input;
        return;
    }

    T pairsLeft, pairsRight;
    typename T::const_iterator it = input.begin();
    while (it != input.end())
    {
        int left = *it;
        if (++it != input.end())
        {
            int right = *it;
            if (left > right)
                std::swap(left, right);
            pairsLeft.push_back(left);
            pairsRight.push_back(right);
            ++it;
        }
        else
        {
            pairsLeft.push_back(left);
        }
    }

    T sortedRight;

    recursiveMergeSort(pairsRight, sortedRight);
    insertWithBinarySearch(sortedRight, pairsLeft);
    output = sortedRight;
}

template <typename T>
void PmergeMe<T>::mergeInsertionSort()
{
    if (this->_container.empty()) return;
    if (_container.size() <= 1) return;

    T sortedContainer;
    recursiveMergeSort(this->_container, sortedContainer);
    this->_container = sortedContainer;
}
