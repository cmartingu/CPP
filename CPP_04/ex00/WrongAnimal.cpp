#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):type("wrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "WrongAnimal Copy Constructor called with type "<< this->getType() << std::endl;
}


WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called with type "<< this->getType() << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void WrongAnimal::makeSound(void)const
{
	std::cout << this->getType() << " says WrongAnimal sounds!" << std::endl;
}

std::string	const   &WrongAnimal::getType(void)const
{
	return (this->type);
}

void    WrongAnimal::setType(std::string const &type)
{
    this->type = type;
}