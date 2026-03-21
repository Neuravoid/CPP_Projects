#include "Fixed.hpp"
#include <iostream>

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
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPointValue);
}

void Fixed::setRawBits( int rawBits )
{
    this->_fixedPointValue = rawBits;
}