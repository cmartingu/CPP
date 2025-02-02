#include "Fixed.hpp"

const float	ft_exp(float base, int exp)
{
	float	res;

	if (exp == 0)
		return (1);
	if (exp < 0)
	{
		exp *= -1;
		base = 1 / base;
	}
	res = base;
	while (--exp)
		res *= base;
	return (res);
}

const int	Fixed::fract_bits = 8;

Fixed::Fixed(void): point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val): point(val * ft_exp(2, this->fract_bits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val): point(roundf(val * ft_exp(2, this->fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed	&Fixed::operator=(const Fixed &to_copy)
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
	return (this->point);
}

void	Fixed::setRawBits(int const raw)
{
	this->point = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->point * ft_exp(2, -this->fract_bits));
}

int		Fixed::toInt(void) const
{
	return (this->point * ft_exp(2, -this->fract_bits));
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	str << fixed_nbr.toFloat();
	return (str);
}