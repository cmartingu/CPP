#include "DogCat.hpp"

//Dog
Dog::Dog(void): Animal("dog")
{
	std::cout << "Dog constructor was called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	*this = copy;
	std::cout << "Copy constructor called with type " << this->getType() << std::endl;
}

Dog::~Dog(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
}

Dog		&Dog::operator=(Dog const &copy)
{
	std::cout << "Assignment dog operator called"  << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Animal type " << this->type << " barks" << std::endl;
}


//Cat
Cat::Cat(void): Animal("cat")
{
	std::cout << "cat constructor was called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	*this = copy;
	std::cout << "Copy constructor called with type " << this->getType() << std::endl;
}

Cat::~Cat(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
}

Cat		&Cat::operator=(Cat const &copy)
{
	std::cout << "Assignment cat operator called"  << std::endl;
	if (this != &copy)
		*this = copy;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Animal type " << this->type << " says \"meow\"" << std::endl;
}