#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
	std::string	name;
	int			number;
}	Data;

class Serializer
{
	private:
		//constructors & destructors
			Serializer(void);
			Serializer(Serializer const &copy);
			~Serializer(void);

		//Assignment operators
			Serializer &operator=(Serializer const &copy);

	public:
		//public methods
			static uintptr_t serialize(Data *ptr);//It takes a pointer and converts it to the unsigned integer type uintptr_t
			static Data *deserialize(uintptr_t raw);//It takes an unsigned integer parameter and converts it to a pointer to Data.
};

#endif