#include "iter.hpp"
#include <string>

int main(void)
{
    int intArray[5] = {1, 2, 3, 4, 5};
    ::iter(intArray, 5, printElement);
    std::cout << std::endl;

    std::string strArray[3] = {"hello", "world", "!"};
    ::iter(strArray, 3, printElement);
    
    std::cout << std::endl;
    ::capitalizer(strArray[0], strArray[0].length());
    ::iter(strArray, 3, printElement);

    return (0);
}