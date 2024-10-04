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

        void        mergeInsertionSort(typename T::iterator first, typename T::iterator last, T& sorted);
        void        mergeSorted(T& left, T& right, T& sorted);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        PmergeMe&   operator=(const PmergeMe& other);

        void        fillContainer(int argc, char **argv);
        void        printContainer(printMsg msg);
        void        fordJohnsonAlgorithm();
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
void    PmergeMe<T>::mergeSorted(T& left, T& right, T& sorted)
{
    typename T::iterator    itLeft = left.begin();
    typename T::iterator    itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft < *itRight)
            sorted.push_back(*itLeft++);
        else
            sorted.push_back(*itRight++);
    }
    
    while (itLeft != left.end())
        sorted.push_back(*itLeft++);
    
    while (itRight != right.end())
        sorted.push_back(*itRight++);
}

template <typename T>
void    PmergeMe<T>::mergeInsertionSort(typename T::iterator first, typename T::iterator last, T& sorted)
{
    if (std::distance(first, last) <= 1)
    {
        if (first != last)
            sorted.push_back(*first);
        return ;
    }

    T                       pairsLeft, pairsRight;
    typename T::iterator    it = first;

    while (it != last)
    {
        int left = *it;

        if (++it != last)
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

    T   sortedLeft, sortedRight;

    mergeInsertionSort(pairsLeft.begin(), pairsLeft.end(), sortedLeft);
    mergeInsertionSort(pairsRight.begin(), pairsRight.end(), sortedRight);

    mergeSorted(sortedLeft, sortedRight, sorted);
}

template <typename T>
void    PmergeMe<T>::fordJohnsonAlgorithm()
{
    if (this->_container.empty()) return;
    if (_container.size() <= 1) return;

    T sorted;
    
    mergeInsertionSort(_container.begin(), _container.end(), sorted);
    
    this->_container = sorted;
}