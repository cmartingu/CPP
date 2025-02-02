#include "../include/Animal.hpp"

Animal::Animal(void): type("default")
{
	std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(std::string const &type): type(type)
{
	std::cout << "Animal constructor called with type " << this->type << std::endl;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called with type " << this->type << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal with type " << this->type << " destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Assignment operator called with type " << this->type << std::endl;
	return *this;
}

std::string const	&Animal::getType(void) const
{
	return this->type;
}

void	Animal::setType(std::string const &type)
{
	this->type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Default animal makes no sound" << std::endl;
}