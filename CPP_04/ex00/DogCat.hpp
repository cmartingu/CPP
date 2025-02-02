#ifndef DOGCAT_HPP
# define DOGCAT_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		//Constructors & destructors
			Dog(void);
			Dog(Dog const &copy);
			~Dog(void);

		//Operators
			Dog &operator=(Dog const &copy);

		//Functions
			void	makeSound(void) const;
};

class Cat: public Animal
{
	public:
		//Constructors & destructors
			Cat(void);
			Cat(Cat const &copy);
			~Cat(void);

		//Operators
			Cat &operator=(Cat const &copy);

		//Functions
			void	makeSound(void) const;
};

#endif