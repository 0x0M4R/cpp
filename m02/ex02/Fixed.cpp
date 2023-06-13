#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(int const input)
{
	this->value = input << this->bits;
}

Fixed::Fixed(float const input)
{
	this->value = roundf(input * (1 << this->bits));
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
	return os << rhs.toFloat();
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	this->value = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->toFloat() > rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const &rhs)
{
	if (this->toFloat() < rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->toFloat() >= rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->toFloat() <= rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &rhs)
{
	if (this->toFloat() == rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->toFloat() != rhs.toFloat())
		return true;
	return false;
}

Fixed &Fixed::operator++(void)
{
	++this->value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(this->toFloat());
	++this->value;
	return copy;
}

Fixed &Fixed::operator--(void)
{
	--this->value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(this->toFloat());
	--this->value;
	return copy;
}

//const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b )
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}
Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((double)this->value / (double)(1 << this->bits));
}

int Fixed::toInt(void) const
{
	return this->value >> this->bits;
}