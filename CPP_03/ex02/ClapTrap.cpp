#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): HitPoints(100), EnergyPoints(50), AttackDamage(20)
{
	std::cout << "ClapTrap constructor called with no name" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): name(name), HitPoints(100), EnergyPoints(50), AttackDamage(20)
{
	std::cout << "ClapTrap constructor called, named: " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << "ClapTrap copy constructor called, named: " << this->name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->name << " ClapTrap destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
	else if (this->HitPoints > 0 && this->EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can´t attack (not enough energy points)" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " can´t attack because it is already dead" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints > 0)
	{
		this->HitPoints -=amount;
		std::cout << "ClapTrap " << name << " took " << amount << " points of dammage. " << HitPoints << " hit points left" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " can´t take dammage because he is already dead" << std::endl;
	}
	if (this->HitPoints < 0)
		this->HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->HitPoints +=amount;
		std::cout << "ClapTrap " << name << " got back " << amount << " hit points . " << HitPoints << " hit points left" << std::endl;
	}
	else if (this->EnergyPoints <= 0 && this->HitPoints > 0)
	{
		std::cout << this->name << " ClapTrap can´t get repaired because he hasn´t got enough energy points" << std::endl;
	}
	else
	{
		std::cout << this->name << " can´t get repaired because he is already dead" << std::endl;
	}
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << "Assignment operator for ClapTrap called, named "<< copy.name << std::endl;
	this->name = copy.getName();
	this->HitPoints = copy.getHitPoints();
	this->AttackDamage = copy.getAttackDamage();
	this->EnergyPoints = copy.getEnergyPoints();
	return (*this);
}

std::string const	&ClapTrap::getName(void) const
{
	return (this->name);
}

int const	&ClapTrap::getHitPoints(void) const
{
	return (this->HitPoints);
}

int const	&ClapTrap::getEnergyPoints(void) const
{
	return (this->EnergyPoints);
}

int const	&ClapTrap::getAttackDamage(void) const
{
	return (this->AttackDamage);
}

void	ClapTrap::setName(std::string const &name)
{
	this->name = name;
}

void	ClapTrap::setHitPoints(int const &amount)
{
	this->HitPoints = amount;
}

void	ClapTrap::setEnergyPoints(int const &amount)
{
	this->EnergyPoints = amount;
}

void	ClapTrap::setAttackDamage(int const &amount)
{
	this->AttackDamage = amount;
}