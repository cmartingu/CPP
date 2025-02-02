#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for target " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm("ShrubberyCreationForm", 145, 137), target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called for target " 
	<< this->getTarget() << " named " << this->getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm deconstructor " << this->getName() << " called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "ShrubberyCreationForm assignment operator called for " << this->getTarget() << std::endl;
	if (this != &copy)//se pone por que sino hay un parámetro que no se usa
		return *this;
	return *this; //Se devuelve lo que hay porque todo son constantes
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile ((this->getTarget() + "_shrubbery").c_str());
		for(int i = 0; i < 3; i++)
		{
			outfile << 
			"         *" << std::endl <<
			"        /|\\" << std::endl <<
			"       /*|O\\" << std::endl <<
			"      /*/|\\*\\" << std::endl <<
			"     /X/O|*\\X\\" << std::endl <<
			"    /*/X/|\\X\\*\\" << std::endl <<
			"   /O/*/X|*\\O\\X\\" << std::endl <<
			"  /*/O/X/|\\X\\O\\*\\" << std::endl <<
			" /X/O/*/X|O\\X\\*\\O\\" << std::endl <<
			"/O/X/*/O/|\\X\\*\\O\\X\\" << std::endl <<
			"        |X|" << std::endl <<
			"        |X|" << std::endl << std::endl;
		}
		outfile.close();
	}
}

std::string const &ShrubberyCreationForm::getTarget(void) const
{
	return this->target;
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm *src)
{
	if (src->getIsSigned())
		str << "ShrubberyCreationForm " << src->getName() << ":" << std::endl << "\t-Sign Grade: " << src->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << src->getGradeExec() << std::endl 
		<< "\t-Is signed: Yes" << std::endl << "\t-Target: " << src->getTarget() << std::endl;
	else
		str << "ShrubberyCreationForm " << src->getName() << ":" << std::endl << "\t-Sign Grade: " << src->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << src->getGradeExec() << std::endl 
		<< "\t-Is signed: No" << std::endl << "\t-Target: " << src->getTarget() << std::endl;
	return str;
}
