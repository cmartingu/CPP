#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>

template < typename T>
class Array
{
	private:
		T				*array;
		unsigned int	len;

	public:
		//constructors
			Array(void): array(NULL), len(0){}

			Array(unsigned int const &len): array(NULL), len(len)
			{
				if (len > 0)
					array = new T[len];
			}

			Array(Array const &copy): array(new T[copy.size()]), len(copy.size())
			{
				for (int i = 0; i < this->size(); i++)
					this->array[i] = copy.array[i];
			}

		//destructors
			~Array(void)
			{
				delete []array;
			}

		//assignment operators
			Array	&operator=(Array const &copy)
			{
				if (this != &copy)
				{
					delete []array;
					len = copy.size();
					array = new T[len];
					for (unsigned int i=0; i < len; i++)
						array[i] = copy.array[i];
				}
				return *this;
			}

			T	&operator[](unsigned int i)
			{
				if (i >= this->len)
					throw IncorrectIndexException();
				return (this->array[i]);
			}

			T const	&operator[](unsigned int i) const
			{
				if (i >= this->len)
					throw IncorrectIndexException();
				return (this->array[i]);
			}

		//public methods
			int size(void) const
			{
				return this->len;
			}

		//exception
			class IncorrectIndexException: public std::exception
			{
				public:
					virtual const char *what() const throw()
					{
						return ("Index out of bounds");
					}
			};
};
