#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    int _rawBits;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(int const value);
    Fixed(float const value);
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
