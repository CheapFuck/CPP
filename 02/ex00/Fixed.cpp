#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointNumberValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : fixedPointNumberValue(other.fixedPointNumberValue)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedPointNumberValue = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits() const
{    
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointNumberValue;
}

// Setter
void Fixed::setRawBits(int const raw)
{
    fixedPointNumberValue = raw;
}


