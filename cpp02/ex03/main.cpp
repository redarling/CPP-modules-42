#include <iostream>
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
    Point   check_point5(7, 0.3);

    std::cout << "Triangle (1,1), (5 -1), (10, 1)" << std::endl;

    std::cout << "5,5:" << bsp(first, second, third, check_point) << std::endl;
    std::cout << "2,1:" << bsp(first, second, third, check_point2) << std::endl;
    std::cout << "5,0:" << bsp(first, second, third, check_point3) << std::endl;
    std::cout << "6,3:" << bsp(first, second, third, check_point4) << std::endl;
    std::cout << "1,1:" << bsp(first, second, third, first) << std::endl;
    std::cout << "7, 0.3:" << bsp(first, second, third, check_point5) << std::endl << std::endl;
    
    return (0);
}