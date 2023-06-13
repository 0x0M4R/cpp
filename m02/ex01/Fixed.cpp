#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(int const input)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = input << this->bits;
}

Fixed::Fixed(float const input)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf( input * ( 1 << this->bits ) );
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this=copy;
}

std::ostream& operator<<(std::ostream& os, Fixed const &rhs)
{
  return ( os<<rhs.toFloat() );
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return ( *this );
}

int		Fixed::getRawBits(void) const
{
	return ( this->value );
}

void	Fixed::setRawBits(int const raw)
{
	this->value=raw;
}

float Fixed::toFloat( void ) const
{
	return ( (double)this->value / (double)(1<<this->bits) );
}

int Fixed::toInt( void ) const
{
	return ( this->value >> this->bits );
}