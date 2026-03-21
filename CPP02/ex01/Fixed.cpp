#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(rs.getRawBits());
    return *this;
}

Fixed::Fixed(Fixed const &rawPoint)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rawPoint.getRawBits());    
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return(this->_fixedPointValue);
}

void Fixed::setRawBits( int rawBits )
{
    this->_fixedPointValue = rawBits;
}
Fixed::Fixed(const int value)
{
    this->setRawBits(value*256);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{  
    this->setRawBits(roundf(value * 256));
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt( void ) const
{
    return(this->getRawBits() >> 8);
}

float Fixed::toFloat( void ) const
{
    return((float)this->getRawBits() / 256);
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    return(o << i.toFloat());
}