#ifndef DOGCAT_HPP
# define DOGCAT_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
			Brain *brain;
	public:
		//Constructors & destructors
			Dog(void);
			Dog(Dog const &copy);
			~Dog(void);

		//Operators
			Dog &operator=(Dog const &copy);

		//Functions
			void	makeSound(void) const;

		//getters & setters
			std::string	getIdea(int i) const;
			void	setIdea(size_t i, std::string idea);
};

class Cat: public Animal
{
	private:
			Brain *brain;
	public:
		//Constructors & destructors
			Cat(void);
			Cat(Cat const &copy);
			~Cat(void);

		//Operators
			Cat &operator=(Cat const &copy);

		//Functions
			void	makeSound(void) const;
		
		//getters & setters
			std::string	getIdea(int i) const;
			void	setIdea(size_t i, std::string idea);
};

#endif