#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called for target " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm("RobotomyRequestForm", 72, 45), target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called for target " 
	<< this->getTarget() << " named " << this->getName() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm deconstructor " << this->getName() << " called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "RobotomyRequestForm assignment operator called for " << this->getTarget() << std::endl;
	if (this != &copy)//se pone por que sino hay un parámetro que no se usa
		return *this;
	return *this; //Se devuelve lo que hay porque todo son constantes
}

static int robot_fail = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else if (robot_fail++ % 2)
		std::cout << "**MAKES DRILLING NOISES**" << std::endl << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string const &RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm *src)
{
	if (src->getIsSigned())
		str << "RobotomyRequestForm " << src->getName() << ":" << std::endl << "\t-Sign Grade: " << src->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << src->getGradeExec() << std::endl 
		<< "\t-Is signed: Yes" << std::endl << "\t-Target: " << src->getTarget() << std::endl;
	else
		str << "RobotomyRequestForm " << src->getName() << ":" << std::endl << "\t-Sign Grade: " << src->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << src->getGradeExec() << std::endl 
		<< "\t-Is signed: No" << std::endl << "\t-Target: " << src->getTarget() << std::endl;
	return str;
}