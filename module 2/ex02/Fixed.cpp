#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    _rawBits = 0;
}

Fixed::Fixed(int const value)
{
    _rawBits = value * (1 << _bits);
}

Fixed::Fixed(float const value)
{
    _rawBits = roundf(value * (1 << _bits));
}

Fixed::Fixed(Fixed const &other)
{
    _rawBits = other._rawBits;
}

Fixed &Fixed::operator=(Fixed const &other)
{
    _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_rawBits) / (1 << _bits);
}

int Fixed::toInt(void) const
{
    return _rawBits / (1 << _bits);
}

bool Fixed::operator>(Fixed const &other) const
{
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(Fixed const &other) const
{
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(Fixed const &other) const
{
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(Fixed const &other) const
{
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(Fixed const &other) const
{
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(Fixed const &other) const
{
    return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(Fixed const &other) const
{
    Fixed result;
    // (a + b) => _rawBits belongs to a, and other._rawBits belongs to b.
    result._rawBits = _rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(Fixed const &other) const
{
    Fixed result;
    result._rawBits = _rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator*(Fixed const &other) const
{
    Fixed result;
    // Raw multiplication has two scale factors so we need to lose one
    float raw = static_cast<float>(_rawBits) * other._rawBits / (1 << _bits);
    result._rawBits = roundf(raw);
    return result;
}

Fixed Fixed::operator/(Fixed const &other) const
{
    Fixed result;
    float raw = static_cast<float>(_rawBits) * (1 << _bits) / other._rawBits;
    result._rawBits = roundf(raw);
    return result;
}

// Update then return a reference to the obj
Fixed &Fixed::operator++(void)
{
    ++_rawBits;
    return *this;
}

// Return prev version
Fixed Fixed::operator++(int)
{
    Fixed previous(*this);
    ++(*this);
    return previous;
}

Fixed &Fixed::operator--(void)
{
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed previous(*this);
    --(*this);
    return previous;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a <= b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return a <= b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a >= b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return a >= b ? a : b;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return out;
}
