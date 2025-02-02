#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter
{
	private:
        //constructor & destructors
			ScalarConverter(void);
			ScalarConverter(ScalarConverter const &copy);
			~ScalarConverter(void);
		
		//Assignment operators
			ScalarConverter &operator=(ScalarConverter const &copy);

        //private methods
            static void convertChar(std::string const &src);
			static void	convertInt(std::string const &src);
			static void	convertFloat(std::string const &src);
			static void	convertDouble(std::string const &src);

	public:
			static void convert(std::string const &str);
};

std::ostream	&operator<<(std::ostream &str, ScalarConverter const &src);

#endif