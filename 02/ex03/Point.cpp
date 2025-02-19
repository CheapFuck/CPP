
#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(Point const& other)
{
	*this = other;
}

Point::Point(Fixed const x, Fixed const y): x(x), y(y) {}

Point&	Point::operator=(Point const& other)
{
	(void)other;
	return *this;
}

Fixed const &Point::getX(void) const
{
	return x;
}

Fixed const &Point::getY(void) const
{
	return y;
}