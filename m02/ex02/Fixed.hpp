#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static int const bits = 8;

	public:
		Fixed( void );
		Fixed( int const raw );
		Fixed( float const raw );
		~Fixed( void );
		Fixed( Fixed const &copy );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed &operator=( Fixed const &rhs );
		bool operator>( Fixed const &rhs );
		bool operator<( Fixed const &rhs );
		bool operator>=( Fixed const &rhs );
		bool operator<=( Fixed const &rhs );
		bool operator==( Fixed const &rhs );
		bool operator!=( Fixed const &rhs );
		Fixed operator+( Fixed const &rhs );
		Fixed operator-( Fixed const &rhs );
		Fixed operator*( Fixed const &rhs );
		Fixed operator/( Fixed const &rhs );
		Fixed &operator++( void );
		Fixed operator++( int );
		Fixed &operator--( void );
		Fixed operator--( int );
		static Fixed& max( Fixed &a, Fixed &b );
		static const Fixed& max( const Fixed &a, const Fixed &b );
		static Fixed& min( Fixed &a, Fixed &b );
		static const Fixed& min( const Fixed &a, const Fixed &b );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
std::ostream &operator<<( std::ostream &os, Fixed const &rhs );

#endif