#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int _rawBits; // the actual number fully
    static const int _bits = 8; // the fractional part bits number (where is the point)

public:
    Fixed();
    // this is called a copy constructor. 
    Fixed(Fixed const &other);
    // Used by a = b: copies b raw value into existing a and returns a by reference.
    Fixed &operator=(Fixed const &other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif

/*
Example: overloading + (for learning).

Declare this in the public section of Fixed:
    Fixed operator+(Fixed const &other) const;

Define it in Fixed.cpp:
    Fixed Fixed::operator+(Fixed const &other) const
    {
        Fixed result;
        result._rawBits = _rawBits + other._rawBits;
        return result;
    }

Usage:
    Fixed sum = a + b; // Equivalent to a.operator+(b).

Here, this points to a and other refers to b.
The trailing const means a is not modified; other is also read-only.
Unlike assignment, + returns a new object by value, not a reference.
Returning a reference to local result would be invalid after it is destroyed.
Fixed const &other means you cannot modify b through other.
The trailing const means the function cannot modify a’s ordinary member variables.
*/
