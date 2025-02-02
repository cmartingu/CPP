#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		//constructors & detructors
			FragTrap(void);
			FragTrap(FragTrap const &copy);
			FragTrap(std::string const &name);
			~FragTrap(void);

		//functions
			void	highFivesGuys(void);

		//operators
			FragTrap	&operator=(FragTrap const &copy);
};

#endif