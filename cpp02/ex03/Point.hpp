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

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif