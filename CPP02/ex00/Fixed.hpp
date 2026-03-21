#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public:
    Fixed();
    Fixed(Fixed const &a);
    Fixed& operator=(Fixed const &rs); 
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();


};
 
#endif
