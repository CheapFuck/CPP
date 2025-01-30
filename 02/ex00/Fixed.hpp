#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>


class Fixed
{
private:
    int fixedPointNumberValue; // The raw fixed-point value
    static const int fractionalBits = 8; // Number of fractional bits (constant)

public:
    // Default constructor
    Fixed();

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
};

#endif // FIXED_HPP