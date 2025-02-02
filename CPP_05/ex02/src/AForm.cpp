#include "../include/AForm.hpp"

AForm::AForm(void): name("default"), isSigned(false), gradeSign(150), gradeExec(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &name): name(name), isSigned(false), gradeSign(150), gradeExec(150)
{
	std::cout << "AForm constructor named " << this->getName() << " called" << std::endl;
}

AForm::AForm(int const &signG, int const &signE): name("default"), isSigned(false), gradeSign(signG), gradeExec(signE)
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << signG << " and execution-grade of " << signE << std::endl;
	if (signG > 150 || signE > 150)
		throw(AForm::GradeTooLowException());
	else if (signG < 1 || signE < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(std::string const &name, int const &signG, int const &signE): name(name), isSigned(false), gradeSign(signG), gradeExec(signE)
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << signG << " and execution-grade of " << signE << std::endl;
	if (signG > 150 || signE > 150)
		throw(AForm::GradeTooLowException());
	else if (signG < 1 || signE < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(AForm const &copy): name(copy.getName()), gradeSign(copy.getGradeSign()), gradeExec(copy.getGradeExec())
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getGradeSign() << " and execution-grade of " 
	<< this->getGradeExec();
	this->isSigned = copy.getIsSigned();
	if (this->isSigned)
		std::cout << " and the form is signed" << std::endl;
	else
		std::cout << " and the form is not signed" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Destructor called for AForm " << this->getName() << std::endl;
}

AForm &AForm::operator=(AForm const &copy)
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getGradeSign() << " and execution-grade of " 
	<< this->getGradeExec();
	if (this != &copy)
		this->isSigned = copy.getIsSigned(); //No igualamos el resto de cosas porque son constantes, es decir, invariables
	return *this;
}

void	AForm::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > this->getGradeSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (!this->getIsSigned())
	{
		this->isSigned = true;
		std::cout << this->getName() << " AForm was signed by Bureaucrat " << src.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

std::string const	&AForm::getName(void) const
{
	return this->name;
}

bool const			&AForm::getIsSigned(void) const
{
	return this->isSigned;
}

int const			&AForm::getGradeSign(void) const
{
	return this->gradeSign;
}

int const			&AForm::getGradeExec(void) const
{
	return this->gradeExec;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
}

std::ostream	&operator<<(std::ostream &str, AForm *form)
{
	if (form->getIsSigned())
		str << "AForm " << form->getName() << ":" << std::endl << "\t-Sign Grade: " << form->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << form->getGradeExec() << std::endl << "\t-Is signed: Yes" << std::endl;
	else
		str << "AForm " << form->getName() << ":" << std::endl << "\t-Sign Grade: " << form->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << form->getGradeExec() << std::endl << "\t-Is signed: No" << std::endl;
	return str;
}