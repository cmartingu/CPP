#include "../include/Form.hpp"

Form::Form(void): name("default"), isSigned(false), gradeSign(150), gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name): name(name), isSigned(false), gradeSign(150), gradeExec(150)
{
	std::cout << "Form constructor named " << this->getName() << " called" << std::endl;
}

Form::Form(int const &signG, int const &signE): name("default"), isSigned(false), gradeSign(signG), gradeExec(signE)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << signG << " and execution-grade of " << signE << std::endl;
	if (signG > 150 || signE > 150)
		throw(Form::GradeTooLowException());
	else if (signG < 1 || signE < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(std::string const &name, int const &signG, int const &signE): name(name), isSigned(false), gradeSign(signG), gradeExec(signE)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << signG << " and execution-grade of " << signE << std::endl;
	if (signG > 150 || signE > 150)
		throw(Form::GradeTooLowException());
	else if (signG < 1 || signE < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(Form const &copy): name(copy.getName()), gradeSign(copy.getGradeSign()), gradeExec(copy.getGradeExec())
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getGradeSign() << " and execution-grade of " 
	<< this->getGradeExec();
	this->isSigned = copy.getIsSigned();
	if (this->isSigned)
		std::cout << " and the form is signed" << std::endl;
	else
		std::cout << " and the form is not signed" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Destructor called for Form " << this->getName() << std::endl;
}

Form &Form::operator=(Form const &copy)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getGradeSign() << " and execution-grade of " 
	<< this->getGradeExec();
	if (this != &copy)
		this->isSigned = copy.getIsSigned(); //No igualamos el resto de cosas porque son constantes, es decir, invariables
	return *this;
}

void	Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > this->getGradeSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (!this->getIsSigned())
	{
		this->isSigned = true;
		std::cout << this->getName() << " Form was signed by Bureaucrat " << src.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

std::string const	&Form::getName(void) const
{
	return this->name;
}

bool const			&Form::getIsSigned(void) const
{
	return this->isSigned;
}

int const			&Form::getGradeSign(void) const
{
	return this->gradeSign;
}

int const			&Form::getGradeExec(void) const
{
	return this->gradeExec;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &str, Form *form)
{
	if (form->getIsSigned())
		str << "Form " << form->getName() << ":" << std::endl << "\t-Sign Grade: " << form->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << form->getGradeExec() << std::endl << "\t-Is signed: Yes" << std::endl;
	else
		str << "Form " << form->getName() << ":" << std::endl << "\t-Sign Grade: " << form->getGradeSign() 
		<< std::endl << "\t-Exec grade: " << form->getGradeExec() << std::endl << "\t-Is signed: No" << std::endl;
	return str;
}