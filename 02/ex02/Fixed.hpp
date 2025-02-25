#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int 				fixedPointNumberValue;
    static const int	fractionalBits = 8;

public:
    // Default constructor
    Fixed();
	Fixed(const int		number);
	Fixed(const float	number);
    // Copy constructor
    Fixed(const Fixed& other);
    // Copy assignment operator overload
    Fixed& operator=(const Fixed& other);
    // Destructor
    ~Fixed();

    int					getRawBits( void ) const;
    void				setRawBits( int const raw );
    float				toFloat( void ) const;
	int					toInt( void ) const;

	// overload member functions
    static Fixed		&min(Fixed& a, Fixed& b);
	static Fixed		&max(Fixed& a, Fixed& b);
	static const Fixed	&min(const Fixed& a, const Fixed& b);
	static const Fixed	&max(const Fixed& a, const Fixed& b);
	// comparison operators
	bool 				operator > (const Fixed& other) const;
	bool 				operator < (const Fixed& other) const;
	bool 				operator >= (const Fixed& other) const;
	bool 				operator <= (const Fixed& other) const;
	bool 				operator == (const Fixed& other) const;
	bool 				operator != (const Fixed& other) const;
	// arithmic operators
	Fixed 				operator + (const Fixed& other) const;
	Fixed 				operator - (const Fixed& other) const;
	Fixed 				operator * (const Fixed& other) const;
	Fixed 				operator / (const Fixed& other) const;
	// increment/decrement
	Fixed 				operator ++ (void);
	Fixed 				operator ++ (int);
	Fixed 				operator -- (void);
	Fixed 				operator -- (int);
};

std::ostream &operator<<(std::ostream& os,  Fixed const& fixed);

#endif