#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
			std::string type;
	public:
		//Constructors & destructors
			Animal(void);
			Animal(std::string const &type);
			Animal(Animal const &copy);
			virtual ~Animal(void);

		//Operators
			Animal &operator=(Animal const &copy);

		//Functions
			virtual void	makeSound(void) const;

		//Getters & setters
			std::string const	&getType(void) const;
			void				setType(std::string const &type);
};

#endif