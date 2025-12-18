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
        ~Fixed();

        Fixed &operator=(const Fixed &to_copy);
        bool operator>(const Fixed &second) const;
        bool operator<(const Fixed &second) const;
        bool operator<=(const Fixed &second) const;
        bool operator>=(const Fixed &second) const;
        bool operator!=(const Fixed &second) const;

        Fixed operator+(const Fixed &second) const;
        Fixed operator-(const Fixed &second) const;
        Fixed operator*(const Fixed &second) const;
        Fixed operator/(const Fixed &second) const;

        Fixed &operator++(); 
        Fixed operator++(int);  

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);


        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};
std::ostream &operator<<(std::ostream &o, Fixed const &F);

#endif