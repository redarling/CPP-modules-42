#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong amount of arguments. Expected: 1" << std::endl;
        return (0);
    }
    
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}