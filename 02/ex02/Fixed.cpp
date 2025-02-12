#include "Fixed.hpp"

// Default constructors
Fixed::Fixed() : fixedPointNumberValue(0)
{
}

Fixed::Fixed(const int number)
{
	fixedPointNumberValue = number <<  fractionalBits;
}

Fixed::Fixed(const float number)
{
	fixedPointNumberValue = static_cast<int>(number * (1 << fractionalBits));
}

// Copy constructors
Fixed::Fixed(const Fixed &other) : fixedPointNumberValue(other.fixedPointNumberValue)
{
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	setRawBits(other.getRawBits());
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
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


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);	
}

// Overload operators
bool Fixed::operator>(const Fixed &other) const
{
	return (fixedPointNumberValue > other.fixedPointNumberValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (fixedPointNumberValue < other.fixedPointNumberValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (fixedPointNumberValue >= other.fixedPointNumberValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (fixedPointNumberValue <= other.fixedPointNumberValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (fixedPointNumberValue == other.fixedPointNumberValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (fixedPointNumberValue != other.fixedPointNumberValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
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

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
 }
