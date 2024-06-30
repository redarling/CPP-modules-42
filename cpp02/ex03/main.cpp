#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   second;
    Point   first;

    Point   third(second);
    Point   forth(4, 5);
    first = forth;

    std::cout << "first x: "<< first.getX() << std::endl;
    std::cout << "first y: "<< first.getY() << std::endl;
    std::cout << "second x: "<< second.getX() << std::endl;
    std::cout << "second y: "<< second.getY() << std::endl;
    std::cout << "third x: "<< third.getX() << std::endl;
    std::cout << "thrid y: "<< third.getY() << std::endl;
    std::cout << "forth x: "<< forth.getX() << std::endl;
    std::cout << "forht y: "<< forth.getY() << std::endl;
    return 0;
}