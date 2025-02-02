#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
			std::string type;
	
	public:
	// Constructors & destructors
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal(void);

	// Overloaded Operators
		WrongAnimal &operator=(const WrongAnimal &src);

	// Public Methods
		virtual void makeSound(void)const;

	// Getters & setters
		std::string const	&getType(void)const;
		void				setType(std::string const &type);
};

#endif