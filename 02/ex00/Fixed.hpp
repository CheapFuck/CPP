#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int 				fixedPointNumberValue;
    static const int 	fractionalBits = 8;

public:
    // Default constructor
    Fixed();
    // Copy constructor
    Fixed(const Fixed &other);
    // Copy assignment operator overload
    Fixed &operator=(const Fixed &other);
    // Destructor
    ~Fixed();

    int 	getRawBits() const;
    void	setRawBits(int const raw);
};

#endif