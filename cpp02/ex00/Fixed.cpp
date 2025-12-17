#include "Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed():_fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const Fixed &to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &to_copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_copy)
    {
        this->_fixed_point = to_copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed_point;
};

void Fixed::setRawBits( int const raw )
{
    this->_fixed_point = raw;
};
