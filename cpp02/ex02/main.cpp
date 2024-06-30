#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl << std::endl;
    
    std::cout << "additional checks" << std::endl;
    Fixed c(10);
    Fixed d(2.5f);

    std::cout << "Value of c: " << c << std::endl;
    std::cout << "Value of d: " << d << std::endl;

    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;

    std::cout << "Pre-decrementing c: " << --c << std::endl;
    std::cout << "Value of c after pre-decrement: " << c << std::endl;
    std::cout << "Post-decrementing c: " << c-- << std::endl;
    std::cout << "Value of c after post-decrement: " << c << std::endl;

    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
    std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;

    std::cout << "Comparison operators:" << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "10 == 10: " << (Fixed(10) == Fixed(10)) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    std::cout << "10 != 10: " << (Fixed(10) != Fixed(10)) << std::endl;

    return 0;
}