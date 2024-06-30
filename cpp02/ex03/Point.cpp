#include "Point.hpp"

Point::Point()
{
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

Point::Point(float x, float y)
{
    Fixed   x_point(x);
    Fixed   y_point(y);

    static_cast<Fixed>(this->x) = x_point;
    static_cast<Fixed>(this->x) = y_point;
}

Point::Point(const Point &point) { *this = point; }

Point& Point::operator=(const Point &point)
{
    if (this != &point)
    {
        static_cast<Fixed>(this->x) = point.x;
        static_cast<Fixed>(this->y) = point.y;
    }
    
    return (*this);
}
        
Point::~Point()
{
    std::cout << "Destructor called" << std::endl;
}

float   Point::getX()
{
    std::cout << static_cast<Fixed>(x) << std::endl;
    return (static_cast<Fixed>(x).toFloat());
}

float   Point::getY()
{
    std::cout << static_cast<Fixed>(y) << std::endl;
    return (static_cast<Fixed>(y).toFloat());
}