#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->setRawBits(0);
    // std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(rs.getRawBits());
    return *this;
}

Fixed::Fixed(Fixed const &rawPoint)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rawPoint.getRawBits());    
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{  
    this->setRawBits(roundf(value * 256));
    // std::cout << "Float constructor called" << std::endl;
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


bool Fixed::operator>(Fixed const &rh) const
{
    if (this->getRawBits() > rh.getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator<(Fixed const &rh) const
{
    if (this->getRawBits() < rh.getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator>=(Fixed const &rh) const
{
    if (this->getRawBits() >= rh.getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator<=(Fixed const &rh) const
{
    if (this->getRawBits() <= rh.getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator==(Fixed const &rh) const
{
    if (this->getRawBits() == rh.getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator!=(Fixed const &rh) const
{
    if (this->getRawBits() != rh.getRawBits())
        return 1;
    return 0;
}

Fixed Fixed::operator+(Fixed const &rh) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + rh.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const &rh) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - rh.getRawBits());
    return result;
}

Fixed Fixed::operator/(Fixed const &rh) const
{
    Fixed result;
    if (rh.getRawBits() == 0)
        std::cerr << "Warning /0" << std::endl;
    float denom = ((float)this->getRawBits() / (float)rh.getRawBits());
    result.setRawBits((int)roundf(denom * 256.0f));
    return result;
}

Fixed Fixed::operator*(Fixed const &rh) const
{
    Fixed result;
    float denom = (float)(this->getRawBits() * rh.getRawBits());
    result.setRawBits(roundf(denom / 256.0f));
    return result;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits());
    this->setRawBits(this->getRawBits() + 1);
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits());
    this->setRawBits(this->getRawBits() - 1);
    return tmp;
}

Fixed& Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed& Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return(b);
    return(a);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return(b);
    return(a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    return(b);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    return(b);
}