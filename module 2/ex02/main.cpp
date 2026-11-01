#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    // The subject's example.
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // Construction, copying, assignment, and conversion.
    Fixed x(5.5f);
    Fixed y(2);
    Fixed copy(x);
    a = y;
    std::cout << "\nCopy: " << copy << ", assignment: " << a << std::endl;
    std::cout << "5.5 as float: " << x.toFloat()
              << ", as int: " << x.toInt() << std::endl;

    // Arithmetic: expected 7.5, 3.5, 11, and 2.75.
    std::cout << "\n5.5 + 2 = " << x + y << std::endl;
    std::cout << "5.5 - 2 = " << x - y << std::endl;
    std::cout << "5.5 * 2 = " << x * y << std::endl;
    std::cout << "5.5 / 2 = " << x / y << std::endl;
    std::cout << "-1.5 * 2 = " << Fixed(-1.5f) * y << std::endl;

    // Comparisons: expected true, false, true, false, true, and true.
    std::cout << std::boolalpha;
    std::cout << "\n5.5 > 2: " << (x > y) << std::endl;
    std::cout << "5.5 < 2: " << (x < y) << std::endl;
    std::cout << "5.5 >= 5.5: " << (x >= copy) << std::endl;
    std::cout << "5.5 <= 2: " << (x <= y) << std::endl;
    std::cout << "5.5 == 5.5: " << (x == copy) << std::endl;
    std::cout << "5.5 != 2: " << (x != y) << std::endl;

    // Each increment/decrement changes the value by 1/256.
    Fixed step;
    std::cout << "\n++step: " << ++step << std::endl;
    std::cout << "step++ returns: " << step++ << std::endl;
    std::cout << "After step++: " << step << std::endl;
    std::cout << "--step: " << --step << std::endl;
    std::cout << "step-- returns: " << step-- << std::endl;
    std::cout << "After step--: " << step << std::endl;

    // Test both the mutable and const min/max overloads.
    std::cout << "\nmin(5.5, 2): " << Fixed::min(x, y) << std::endl;
    std::cout << "max(5.5, 2): " << Fixed::max(x, y) << std::endl;
    Fixed const low(-1);
    Fixed const high(3);
    std::cout << "const min(-1, 3): " << Fixed::min(low, high) << std::endl;
    std::cout << "const max(-1, 3): " << Fixed::max(low, high) << std::endl;

    return 0;
}
