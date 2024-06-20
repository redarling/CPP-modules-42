#include <iostream>
#include <string>

int main(void)
{
    std::string stringORIG = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringORIG;
    std::string& stringREF = stringORIG;

    std::cout << "The memory address of the string variable: " 
            << &stringORIG << std::endl;
    std::cout << "The memory address held by stringPTR: " 
            << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " 
            << &stringREF << std::endl << std::endl;

    std::cout << "The value of the string variable: " 
            << stringORIG << std::endl;
    std::cout << "The value pointed to by stringPTR: " 
            << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " 
            << stringREF << std::endl;

    return (0);
}