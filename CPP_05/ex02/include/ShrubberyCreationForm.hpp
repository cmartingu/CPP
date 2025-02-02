#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class Aform;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string const	target;
		ShrubberyCreationForm(void);
	public:
		//Constructors & desrtuctors
			ShrubberyCreationForm(std::string const &target);
			ShrubberyCreationForm(ShrubberyCreationForm const &copy);
			~ShrubberyCreationForm(void);

		//Assignment operators
			ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &copy);

		//Public Methods
			void	execute(Bureaucrat const &executor)const;

		//getters & setters
			std::string const &getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm *src);

#endif