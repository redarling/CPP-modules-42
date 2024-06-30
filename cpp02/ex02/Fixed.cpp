#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value) : value(value << bits) {}

Fixed::Fixed(const float value) : value(static_cast<int>(roundf(value * (1 << bits)))) {}

Fixed::Fixed(const Fixed &fixed) {*this = fixed;}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->value = fixed.getRawBits();
    
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->value);
}

const int Fixed::getFractionalBits(void)
{
    return (bits);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->value) / (1 << bits));
}

int Fixed::toInt(void) const
{
    return (this->value >> bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool operator>(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() > fixed2.getRawBits());
}

bool operator<(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() < fixed2.getRawBits());
}

bool operator>=(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() >= fixed2.getRawBits());
}

bool operator<=(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() <= fixed2.getRawBits());
}

bool operator==(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() == fixed2.getRawBits());
}

bool operator!=(const Fixed &fixed1, const Fixed &fixed2)
{
    return (fixed1.getRawBits() != fixed2.getRawBits());
}

Fixed operator+(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed   Sum;

    Sum.setRawBits(fixed1.getRawBits() + fixed2.getRawBits());

    return (Sum);
}

Fixed operator-(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed   Difference;

    Difference.setRawBits(fixed1.getRawBits() - fixed2.getRawBits());

    return (Difference);
}

Fixed operator*(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed   Product;

    Product.setRawBits((fixed1.getRawBits() * fixed2.getRawBits()) >> Fixed::getFractionalBits());

    return (Product);
}

Fixed operator/(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed   Quotient;

    Quotient.setRawBits((fixed1.getRawBits() << Fixed::getFractionalBits()) / fixed2.getRawBits());

    return (Quotient);
}

Fixed& Fixed::operator++()
{
    ++value;

    return (*this);
}


Fixed Fixed::operator++(int)
{
    Fixed temp(*this);

    ++(*this);

    return (temp);
}



Fixed&  Fixed::operator--()
{
    --value;

    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);

    --(*this);

    return (temp);
}


Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    else
        return (fixed2);
}

const Fixed&  Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    else
        return (fixed2);
}

Fixed&  Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed2);
    else
        return (fixed1);
}

const Fixed&  Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed2);
    else
        return (fixed1);
}