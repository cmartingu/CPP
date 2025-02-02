#include "../include/Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
    std::cout << "Intern Copy Constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern Deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;//no hay nada que copiar, ya que no hay variables
}

// static functions for makeForm**********************************************
static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods******************************************
AForm	*Intern::makeForm(const std::string form_to_create, const std::string target_for_form)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cout << "\033[33mIntern can not create a form called " << form_to_create << "\033[0m" << std::endl;
	return (NULL);
}