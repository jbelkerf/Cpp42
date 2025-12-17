#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int _fixed_point;
        static const int _fractional;
    public:
        Fixed();
        Fixed(const Fixed &to_copy);
        Fixed &operator=(const Fixed &to_copy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif