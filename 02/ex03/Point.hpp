#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(Point const &other);
    Point(Fixed const x, Fixed const y);
    ~Point();

    Point& operator=(Point const &other);

    Fixed const &getX(void) const;
    Fixed const &getY(void) const;
};

#endif
