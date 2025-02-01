#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fixedPointNumberValue;
    static const int fractionalBits = 8;

public:
    // Default constructor
    Fixed();
	Fixed(const int number);
	Fixed(const float number);
    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator overload
    Fixed &operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    // Getter function to return the raw value of the fixed-point number
    int getRawBits() const;

    // Setter function to set the raw value of the fixed-point number
    void setRawBits(int const raw);

    float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os,  Fixed const &fixed);

#endif