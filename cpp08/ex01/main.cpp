#include "Span.hpp"
#include <vector>

int main(void)
{
    /******SUBJECT TEST*******/
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    /******EMPTY TEST*******/
    Span sp2;
    try
    {
        sp2.addNumber(25);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    Span sp3(5);
    try
    {
        sp3.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        sp3.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    /******REALLY BIG SPAN TEST*******/

    Span sp4(120000);

    std::vector<int> vec;
    for (int i = 0; i < 100000; ++i)
        vec.push_back(i);
    
    try
    {
        sp4.addRange(vec.begin(), vec.end());
        std::cout << "Shortest Span in sp2: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span in sp2: " << sp4.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
         std::cerr << e.what() << std::endl;
    }

    try
    {
        sp4.addRange(vec.begin(), vec.end());
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}