#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called for target " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm("PresidentialPardonForm", 25, 5), target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called for target " 
	<< this->getTarget() << " named " << this->getName() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm deconstructor " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	std::cout << "PresidentialPardonForm assignment operator called for " << this->getTarget() << std::endl;
	if (this != &copy)//se pone por que sino hay un parámetro que no se usa
		return *this;
	return *this; //Se devuelve lo que hay porque todo son constantes
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string const &PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm *src)
{
	if (src->getIsSigned())
		str << "PresidentialPardonForm " << src->getName() << ":" << std::endl << "\t-Sign Grade: " << src->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << src->getGradeExec() << std::endl 
		<< "\t-Is signed: Yes" << std::endl << "\t-Target: " << src->getTarget() << std::endl;
	else
		str << "PresidentialPardonForm " << src->getName() << ":" << std::endl << "\t-Sign Grade: " << src->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << src->getGradeExec() << std::endl 
		<< "\t-Is signed: No" << std::endl << "\t-Target: " << src->getTarget() << std::endl;
	return str;
}