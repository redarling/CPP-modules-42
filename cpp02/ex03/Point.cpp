#include "Point.hpp"

Point::Point() {}

Point::Point(float x_point, float y_point) : x(x_point), y(y_point) {}

Point::Point(const Point &point) : x(point.x), y(point.y) {}

Point& Point::operator=(const Point &point)
{   
    return (*this);
}
        
Point::~Point() {}

float   Point::getX()
{
    return (static_cast<Fixed>(x).toFloat());
}

float   Point::getY()
{
    return (static_cast<Fixed>(y).toFloat());
}