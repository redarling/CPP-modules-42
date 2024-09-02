#include "easyfind.hpp"

int main(void)
{
    std::vector<int>    v;
    
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    try
    {
        std::vector<int>::const_iterator it = easyfind(v, 5);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::const_iterator it = easyfind(v, 42);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
