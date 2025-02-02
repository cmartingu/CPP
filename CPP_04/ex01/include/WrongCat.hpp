#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
	// Constructors & destructors
		WrongCat(void);
		WrongCat(const WrongCat &copy);
		~WrongCat(void);

	// Overloaded Operators
		WrongCat &operator=(const WrongCat &src);

	// Functions
		void makeSound(void)const;
};

#endif