#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int    fract_bits;
		int                 point;
	public:
		Fixed();
		Fixed(Fixed const &to_copy);
		~Fixed();
		Fixed	&operator = (const Fixed &to_copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif