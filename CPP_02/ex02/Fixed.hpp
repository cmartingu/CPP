#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int    fract_bits;
		int                 point;
	public:
		//Constructores
			Fixed();
			Fixed(const int val);
			Fixed(const float val);
			Fixed(Fixed const &to_copy);

		//Destructor
			~Fixed();

		//Operadores
			Fixed	&operator=(const Fixed &to_copy);

			//Comparación
			bool operator>(Fixed to_cmp)const;
			bool operator<(Fixed to_cmp)const;
			bool operator>=(Fixed to_cmp)const;
			bool operator<=(Fixed to_cmp)const;
			bool operator==(Fixed to_cmp)const;
			bool operator!=(Fixed to_cmp)const;

			//Aritméticos
			float operator+(Fixed aritm);
			float operator-(Fixed aritm);
			float operator*(Fixed aritm);
			float operator/(Fixed aritm);

			//pre
			Fixed operator++();
			Fixed operator--();

			//post
			Fixed operator++(int);
			Fixed operator--(int);

		//Funciones
			float			toFloat(void) const;
			int				toInt(void) const;
			static			Fixed &min(Fixed &cmp1, Fixed &cmp2);
			static const	Fixed &min(Fixed const &cmp1, Fixed const &cmp2);
			static			Fixed &max(Fixed &cmp1, Fixed &cmp2);
			static const	Fixed &max(Fixed const &cmp1, Fixed const &cmp2);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif