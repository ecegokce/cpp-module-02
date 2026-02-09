#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): rawBits(0)
{}

Fixed::Fixed(const int number)
{
	rawBits = number << fractionalBits;
}

Fixed::Fixed(const float number)
{
	rawBits = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{}

int	Fixed::getRawBits(void) const
{
	return (rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return (rawBits >> fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((static_cast <float> (rawBits)) / (static_cast <float> (1 << fractionalBits)));
}

Fixed	&Fixed::operator=(const Fixed &op)
{
	if (this != &op)
		this->rawBits = op.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	float	val;

	val = fixed.toFloat();
	return (out << val);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.rawBits = this->rawBits + other.rawBits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.rawBits = this->rawBits - other.rawBits;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	result.rawBits = (static_cast <long long> (this->rawBits) * other.rawBits) >> fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	result.rawBits = (static_cast <long long> (this->rawBits) << fractionalBits) / other.rawBits;
	return (result);
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->rawBits > other.rawBits)
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->rawBits < other.rawBits)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->rawBits >= other.rawBits)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->rawBits <= other.rawBits)
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->rawBits == other.rawBits)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->rawBits != other.rawBits)
		return true;
	return false;
}

Fixed	&Fixed::operator++(void)
{
	this->rawBits++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->rawBits++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->rawBits--;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
