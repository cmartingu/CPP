#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		//constructors & detructors
			ScavTrap(void);
			ScavTrap(ScavTrap const &copy);
			ScavTrap(std::string const &name);
			~ScavTrap(void);

		//functions
			void	guardGate(void);

		//operators
			ScavTrap	&operator=(ScavTrap const &copy);
};

#endif