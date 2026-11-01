#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    int _rawBits;
    static const int _bits = 8;

public:
    Fixed(void);
    Fixed(int const value);
    Fixed(float const value);
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
