#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class Aform;

class RobotomyRequestForm: public AForm
{
	private:
		std::string const	target;
		RobotomyRequestForm(void);
	public:
		//Constructors & desrtuctors
			RobotomyRequestForm(std::string const &target);
			RobotomyRequestForm(RobotomyRequestForm const &copy);
			~RobotomyRequestForm(void);

		//Assignment operators
			RobotomyRequestForm	&operator=(RobotomyRequestForm const &copy);

		//Public Methods
			void	execute(Bureaucrat const &executor)const;

		//getters & setters
			std::string const &getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm *src);

#endif