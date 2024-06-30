#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    public:  
        Point();
        Point(float x, float y);
        Point(const Point &point);
        Point& operator=(const Point &point);
        ~Point();
        float   getX();
        float   getY();


    private:
        Fixed const x;
        Fixed const y;
};

#endif