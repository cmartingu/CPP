#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << "FragTrap default constructor called " << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
    std::cout << "FragTrap copied with constructor from ClapTrap " << this->getName() << std::endl;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "FragTrap constructor from ClapTrap " << this->getName() << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor named " << this->getName() << " called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "Assignment operator for FragTrap called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap from ClapTrap " << this->getName() << " high fives everyone" << std::endl;
}