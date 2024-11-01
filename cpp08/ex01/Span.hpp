#ifndef SPAN_HPP
# define SPAN_HPP

# include "SpanIsFull.hpp"
# include "SpanNotPossible.hpp"
# include <climits>
# include <iostream>
# include <set>

class Span
{
    private:
        std::multiset<int>  container;
        unsigned int        size;

    public:
        Span();
        Span(unsigned int size);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);

        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();

        template <typename it>
        void addRange(it first, it last)
        {
            unsigned int    distance = 0;
            it              temp = first;

            while (temp != last)
            {
                ++distance;
                ++temp;
            }

            if (distance > this->size - this->container.size())
                throw SpanIsFull();

            this->container.insert(first, last);
        }
};

#endif