#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base*   generate(void)
{
    int     random_number = rand() % 3;

    switch(random_number)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        default:
            return (new C());
    }
}

void    identify(Base* p)
{
    A*  a = dynamic_cast<A*>(p);

    if (a)
        std::cout << "identified: A (using pointer)" << std::endl;
    else
    {
        B*  b = dynamic_cast<B*>(p);
        if (b)
            std::cout << "identified: B (using pointer)" << std::endl;
        else
        {
            C*  c = dynamic_cast<C*>(p);
            if (c)
                std::cout << "identified: C (using pointer)" << std::endl;
        }
    }
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "identified: A (using reference)" << std::endl;
        (void)a;
        return ;
    }
    catch (const std::bad_cast& e)
    {
        std::cout << "Not A: " << e.what() << std::endl;
    }

    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "identified: B (using reference)" << std::endl;
        (void)b;
        return ;
    }
    catch (const std::bad_cast& e)
    {
        std::cout << "Not B: " << e.what() << std::endl;
    }

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "identified: C (using reference)" << std::endl;
        (void)c;
        return ;
    }
    catch (const std::bad_cast& e)
    {
        std::cout << "Not C: " << e.what() << std::endl;
    }
}

int     main(void)
{
    Base*   base;
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 10; i++)
    {
        base = generate();
        identify(base);
        identify(*base);
        std::cout << std::endl;
        delete (base);
    }
    return (0);
}