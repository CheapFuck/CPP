#include "Fixed.hpp"

// Default constructors
Fixed::Fixed() : fixedPointNumberValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	fixedPointNumberValue = number <<  fractionalBits;
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number)
{
	fixedPointNumberValue = static_cast<int>(roundf(number * (1 << fractionalBits)));  // Round to nearest integer
	// std::cout << "Float constructor called" << std::endl;
}

// Copy constructors
Fixed::Fixed(const Fixed& other) : fixedPointNumberValue(other.fixedPointNumberValue)
{
	*this = other;
    // std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment constructor called\n";
	if (this != &other)
	{
    	setRawBits(other.getRawBits());
	}
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits() const
{    
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);	
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);	
}

// Overload operators
bool Fixed::operator>(const Fixed& other) const
{
	return (fixedPointNumberValue > other.fixedPointNumberValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (fixedPointNumberValue < other.fixedPointNumberValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (fixedPointNumberValue >= other.fixedPointNumberValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (fixedPointNumberValue <= other.fixedPointNumberValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (fixedPointNumberValue == other.fixedPointNumberValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (fixedPointNumberValue != other.fixedPointNumberValue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other != 0)
		return (Fixed(toFloat() / other.toFloat()));
	std::cout << "*CRASH*" << std::endl;
	exit (1);
}

Fixed Fixed::operator++(void)
{
	fixedPointNumberValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(void)
{
	fixedPointNumberValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
    os << fixed.toFloat();
    return os;
 }
