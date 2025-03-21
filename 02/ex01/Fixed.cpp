#include "Fixed.hpp"

// Default constructors
Fixed::Fixed() : fixedPointNumberValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	fixedPointNumberValue = number <<  fractionalBits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number)
{
	fixedPointNumberValue = static_cast<int>(roundf(number * (1 << fractionalBits)));  // Round to nearest integer
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : fixedPointNumberValue(other.fixedPointNumberValue)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment constructor called\n";
	if (this != &other)
	{
    	setRawBits(other.getRawBits());
	}
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits() const
{    
    // std::cout << "getRawBits member function called" << std::endl;
    return fixedPointNumberValue;
}

// Setter
void Fixed::setRawBits(int const raw)
{
    fixedPointNumberValue = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointNumberValue) / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (fixedPointNumberValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
 }
