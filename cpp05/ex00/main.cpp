#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat bob("Bob", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating Bob: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.decrementGrade();
        alice.decrementGrade();
        alice.decrementGrade();
        alice.decrementGrade();
        alice.decrementGrade();
        alice.decrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while incrementing Alice's grade: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat john("John", 150);
        std::cout << john << std::endl;
        john.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while decrementing John's grade: " << e.what() << std::endl;
    }

    return (0);
}
