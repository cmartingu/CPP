#pragma once

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>

class Span
{
	private:
		std::vector<int>	vec;
		unsigned int		N;

	public:
		//constructors
			Span(void);
			Span(unsigned int const &nb);
			Span(Span const &copy);
		
		//Destructors
			~Span(void);
		
		//Assignment operators
			Span &operator=(Span const &copy);
		
		//public methods
			void	addNumber(int const &nb);
			int		shortestSpan(void) const;
			int		longestSpan(void) const;
		
		//getters
			unsigned int const	&getN(void) const;
		
		//exceptions
			class CannotStoreMore: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class NotEnoughNumbers: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};
};

std::ostream &operator<<(std::ostream &str, Span const &src);