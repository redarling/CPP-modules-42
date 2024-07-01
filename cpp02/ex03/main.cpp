#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   first(1, 1);
    Point   second(5, -1);
    Point   third(10, 1);
    Point   check_point(5, 5);
    Point   check_point2(2, 1);
    Point   check_point3(5, 0);
    Point   check_point4(6, 3);

    std::cout << "first x: "<< first.getX() << std::endl;
    std::cout << "first y: "<< first.getY() << std::endl;
    std::cout << "second x: "<< second.getX() << std::endl;
    std::cout << "second y: "<< second.getY() << std::endl;
    std::cout << "third x: "<< third.getX() << std::endl;
    std::cout << "thrid y: "<< third.getY() << std::endl;
    std::cout << "forth x: "<< check_point.getX() << std::endl;
    std::cout << "forth y: "<< check_point.getY() << std::endl;
    std::cout << "5,5:" <<bsp(first, second, third, check_point) << std::endl;
    std::cout << "2,1:" <<bsp(first, second, third, check_point2) << std::endl;
    std::cout << "5,0:" <<bsp(first, second, third, check_point3) << std::endl;
    std::cout << "6,3:" <<bsp(first, second, third, check_point4) << std::endl;
    return (0);
}