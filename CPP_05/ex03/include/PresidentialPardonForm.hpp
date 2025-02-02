#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string const	target;
		PresidentialPardonForm(void);
	public:
		//Constructors & desrtuctors
			PresidentialPardonForm(std::string const &target);
			PresidentialPardonForm(PresidentialPardonForm const &copy);
			~PresidentialPardonForm(void);

		//Assignment operators
			PresidentialPardonForm	&operator=(PresidentialPardonForm const &copy);

		//Public Methods
			void	execute(Bureaucrat const &executor)const;

		//getters & setters
			std::string const &getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm *src);

#endif