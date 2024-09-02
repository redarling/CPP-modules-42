#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <algorithm>
# include <stack>
# include <queue>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T>& other);
        ~MutantStack();
        MutantStack<T>& operator=(const MutantStack<T>& other);

        typedef typename std::stack<T>::container_type::iterator                iterator;
        typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;
        
        iterator                begin();
        iterator                end();
        const_iterator          begin() const;
        const_iterator          end() const;
        reverse_iterator        rbegin();
        reverse_iterator        rend();
        const_reverse_iterator  rbegin() const;
        const_reverse_iterator  rend() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}


template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
    if (this != &other)
    {
        this->c = other.c;
    }
    return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
}


template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
    return (this->c.rend());
}

#endif