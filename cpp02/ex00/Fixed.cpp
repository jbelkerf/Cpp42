#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const Fixed &to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = to_copy.fixed_point;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{

};
    void Fixed::setRawBits( int const raw );
