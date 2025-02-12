#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int 				fixedPointNumberValue;
    static const int 	fractionalBits = 8;

public:
    // Default constructor(s)
    Fixed();
	Fixed(const int number);
	Fixed(const float number);
    // Copy constructor
    Fixed(const Fixed &other);
    // Copy assignment operator overload
    Fixed 	&operator=(const Fixed &other);
    // Destructor
    ~Fixed();

    int 	getRawBits(void) const;
    void 	setRawBits(int const raw);
    float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os,  Fixed const &fixed);

#endif