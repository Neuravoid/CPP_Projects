#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public:
    Fixed();
    Fixed(Fixed const &a);
    Fixed& operator=(Fixed const &rs); 
    Fixed(const int value);
    Fixed(const float value);
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    bool operator>(Fixed const &rh) const;
    bool operator<(Fixed const &rh) const;
    bool operator>=(Fixed const &rh) const;
    bool operator<=(Fixed const &rh) const;
    bool operator==(Fixed const &rh) const;
    bool operator!=(Fixed const &rh) const;
    Fixed operator+(Fixed const &rh) const;
    Fixed operator-(Fixed const &rh) const;
    Fixed operator/(Fixed const &rh) const;
    Fixed operator*(Fixed const &rh) const;
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed& operator++(void);
    Fixed& operator--(void);
    static Fixed& min(Fixed &a, Fixed &b);
    const static Fixed& min(Fixed const &a, Fixed const &b);
    static Fixed& max(Fixed &a, Fixed &b);
    const static Fixed& max(Fixed const &a, Fixed const &b);
    ~Fixed();
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

 
#endif
