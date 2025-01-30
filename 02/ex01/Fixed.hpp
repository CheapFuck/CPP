#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>


class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();

    Fixed(const int intValue);

    Fixed(const float floatValue);

    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);

    ~Fixed();

    int getRawBits() const;

    void setRawBits(int const raw);

    float toFloat() const;

    int toInt() const ;

};

#endif // FIXED_HPP