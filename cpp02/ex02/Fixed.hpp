#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed & operator = (const Fixed &fixed);
        
        int                 getRawBits(void) const;
        static const int    getFractionalBits(void);
        void                setRawBits(int const raw);
        float               toFloat(void) const;
        int                 toInt(void) const;
        
        // increment
        Fixed&              operator++(); // pre
        Fixed               operator++(int); // post
        
        // decrement
        Fixed&              operator--(); // pre
        Fixed               operator--(int); // post
        
        // Comparison operators
        bool                operator>(const Fixed &other) const;
        bool                operator<(const Fixed &other) const;
        bool                operator>=(const Fixed &other) const;
        bool                operator<=(const Fixed &other) const;
        bool                operator==(const Fixed &other) const;
        bool                operator!=(const Fixed &other) const;
    
        // Arithmetic operators
        Fixed               operator+(const Fixed &other) const;
        Fixed               operator-(const Fixed &other) const;
        Fixed               operator*(const Fixed &other) const;
        Fixed               operator/(const Fixed &other) const;
        
        static Fixed&       min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed& min(Fixed const &fixed1, Fixed const &fixed2);
        static Fixed&       max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed& max(Fixed const &fixed1, Fixed const &fixed2);

    private:
        int                 value;
        static const int    bits = 8;

};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif