#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harld suddenly appeared" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl went away" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger" << std::endl << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money" << std::endl << "You didn’t put enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free" << std::endl << "I’ve been coming for years whereas you started working here since last month" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable!" << std::endl << "I want to speak to the manager now" << std::endl;
}

void	Harl::complain(std::string level)
{
	void    (Harl::*ptr_function[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (complains[i] == level)
			(this->*ptr_function[i])();
	}
}