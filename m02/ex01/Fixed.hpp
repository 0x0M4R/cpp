#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					value;
		static int const	bits = 8;
	public:
		Fixed( void );
		Fixed( int const raw );
		Fixed( float const raw );
		~Fixed( void );
		Fixed( Fixed const &copy );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator=( Fixed const &rhs );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
std::ostream& operator<<( std::ostream& os, Fixed const &rhs );
#endif