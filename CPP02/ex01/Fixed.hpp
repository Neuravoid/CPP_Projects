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
    ~Fixed();
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

 
#endif
