#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;

	rawBits = number << fractionalBits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;

	rawBits = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
	std::cout << "Copy assignment operator called" << std::endl;

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
