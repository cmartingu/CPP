#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
			std::string name;
			int			HitPoints;
			int			EnergyPoints;
			int			AttackDamage;
	public:
		//constructors & destructors
			ClapTrap(void);
			ClapTrap(std::string const &name);
			ClapTrap(ClapTrap const &copy);
			~ClapTrap(void);

		//functions
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);

		//Operators
			ClapTrap &operator=(ClapTrap const &copy);

		//getters & setters
			std::string const	&getName(void) const;
			int const			&getHitPoints(void) const;
			int const			&getEnergyPoints(void) const;
			int const			&getAttackDamage(void) const;
			void				setName(std::string const &name);
			void				setHitPoints(int const &amount);
			void				setEnergyPoints(int const &amount);
			void				setAttackDamage(int const &amount);
};

#endif