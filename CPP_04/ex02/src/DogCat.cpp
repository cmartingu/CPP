#include "../include/DogCat.hpp"

//*********************DOG*********************//
Dog::Dog(void): Animal("dog")
{
	std::cout << "Dog constructor was called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog const &copy)
{
	this->type = copy.getType();
	this->brain = new Brain();
	for (int i=0; i < 100; i++)
		this->setIdea(i, copy.getIdea(i));
	std::cout << "Copy constructor called with type " << this->getType() << std::endl;
}

Dog::~Dog(void)
{
	delete(this->brain);
	std::cout << this->getType() << " destructor called" << std::endl;
}

Dog		&Dog::operator=(Dog const &copy)
{
	std::cout << "Assignment dog operator called"  << std::endl;
	if (this != &copy)
	{
		this->type = copy.getType();
		this->brain = new Brain();
		for (int i=0; i < 100; i++)
			this->setIdea(i, copy.getIdea(i));
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Animal type " << this->type << " barks" << std::endl;
}

std::string	Dog::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

void	Dog::setIdea(size_t i, std::string idea)
{
	this->brain->setIdeas(i, idea);
}


//*********************CAT*********************//
Cat::Cat(void): Animal("cat")
{
	std::cout << "cat constructor was called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat const &copy)
{
	this->type = copy.getType();
	this->brain = new Brain();
	for (int i=0; i < 100; i++)
		this->setIdea(i, copy.getIdea(i));
	std::cout << "Copy constructor called with type " << this->getType() << std::endl;
}

Cat::~Cat(void)
{
	delete(this->brain);
	std::cout << this->getType() << " destructor called" << std::endl;
}

Cat		&Cat::operator=(Cat const &copy)
{
	std::cout << "Assignment cat operator called"  << std::endl;
	if (this != &copy)
	{
		this->type = copy.getType();
		this->brain = new Brain();
		for (int i=0; i < 100; i++)
			this->setIdea(i, copy.getIdea(i));
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Animal type " << this->type << " says \"meow\"" << std::endl;
}

std::string	Cat::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

void	Cat::setIdea(size_t i, std::string idea)
{
	this->brain->setIdeas(i, idea);
}