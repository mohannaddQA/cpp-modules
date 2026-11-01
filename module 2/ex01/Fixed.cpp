#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void)
{
    _rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
    // 1 << 8 Same as 2 ^ 8 because we are shifting 1 to 100000000
    _rawBits = value * (1 << _bits);
    // This saves it as int and zeros out the fractional part
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value)
{
    // We want to save as int but keep the fractional part
    // So we move the point right by doing 1 << 8 and round to a representable int
    _rawBits = roundf(value * (1 << _bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
    _rawBits = other._rawBits;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    // Floating-point division preserves the fractional part.
    return static_cast<float>(_rawBits) / (1 << _bits);
}

int Fixed::toInt(void) const
{
    // Integer division discards the fractional part toward zero.
    return _rawBits / (1 << _bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return out;
}
