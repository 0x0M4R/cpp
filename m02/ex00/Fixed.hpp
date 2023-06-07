#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value;
		static int const	bits=8;
	public:
		Fixed(void);
        ~Fixed(void);
		Fixed(Fixed const &copy);
        Fixed & operator=(Fixed const &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif