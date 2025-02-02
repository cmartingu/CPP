#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called for " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name): name(name), grade(150)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int const &grade): name("default"), grade(grade)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade): name(name), grade(grade)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): name(copy.getName())
{
	std::cout << "Copy constructor called for " << this->getName() << " with grade " << copy.getGrade() << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called for " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat assignment operator called for " << copy.getName() << " with grade " << copy.getGrade() << std::endl;
	if (this != &copy)
		this->setGrade(copy.grade);
	return *this;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Incrementing grade of " << this->getName() << std::endl;
	this->setGrade(this->grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Decrementing grade of " << this->getName() << std::endl;
	this->setGrade(this->grade + 1);
}

std::string const	&Bureaucrat::getName(void) const
{
	return this->name;
}

int const			&Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void	Bureaucrat::setGrade(int const &grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat *src)
{
	str << src->getName() << ", bureaucrat grade " << src->getGrade();
	return str;
}