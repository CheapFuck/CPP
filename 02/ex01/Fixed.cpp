#include <iostream>
#include <cmath>
#include "Fixed.hpp"

    Fixed::Fixed() : value(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {
        std::cout << "Int constructor called" << std::endl;
    }

    Fixed::Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits))) {
        std::cout << "Float constructor called" << std::endl;
    }

    Fixed::Fixed(const Fixed &other) : value(other.value) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Fixed& Fixed::operator=(const Fixed &other) {
        if (this != &other) {
            value = other.value;
        }
        std::cout << "Copy assignment operator called" << std::endl;
        return *this;
    }

    Fixed::~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }

    int Fixed::getRawBits() const {
        return value;
    }

    void Fixed::setRawBits(int const raw) {
        value = raw;
    }

    float Fixed::toFloat() const {
        return (float)value / (1 << fractionalBits);
    }

    int Fixed::toInt() const {
        return value >> fractionalBits;
    }

   