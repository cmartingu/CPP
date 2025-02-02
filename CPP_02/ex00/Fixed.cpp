#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

Fixed::Fixed(void): point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &to_copy)
{
	*this = to_copy;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator = (const Fixed &to_copy)
{
	if (this != &to_copy)
		this->point = to_copy.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->point);
}

void	Fixed::setRawBits(int const raw)
{
	this->point = raw;
}