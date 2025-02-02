#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copied with constructor from ClapTrap " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor from ClapTrap " << this->getName() << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor named " << this->getName() << " called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "Assignment operator for ScavTrap called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap from ClapTrap " << this->getName() << " is now in Gate Keeper mode" << std::endl;
}