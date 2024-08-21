#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 100

int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(static_cast<unsigned int>(time(NULL)));
    
    std::cout << "Initializing array with random values:" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    std::cout << "\nTesting copy constructor and assignment operator:" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Copy constructor and assignment operator worked." << std::endl;
        
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != test[i])
            {
                std::cerr << "Error: Copied value does not match original." << std::endl;
                return 1;
            }
        }
        std::cout << "All values matched after copy." << std::endl;
    }

    std::cout << "\nTesting index out of bounds:" << std::endl;
    try
    {
        numbers[-2] = 0; // Should throw exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; // Should throw exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTesting modification and size check:" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    std::cout << "Array size: " << numbers.size() << std::endl;

    delete [] mirror;
    return 0;
}
