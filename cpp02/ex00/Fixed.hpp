#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int fixed_point;
    public:
        static const int fractional;
        Fixed();
        Fixed(const Fixed &to_copy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif