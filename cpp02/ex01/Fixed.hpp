#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixed_point;
        static const int _fractional;
    public:
        Fixed();
        Fixed(int _n);
        Fixed(float _f);
        Fixed(const Fixed &to_copy);
        Fixed &operator=(const Fixed &to_copy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};
        std::ostream &operator<<(std::ostream &o, Fixed const &F);

#endif