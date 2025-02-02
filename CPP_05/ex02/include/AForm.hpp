#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
			std::string const	name;
			bool				isSigned;
			int	const			gradeSign;
			int const			gradeExec;
	public:
		//constructors & destructors
			AForm(void);
			AForm(std::string const &name);
			AForm(int const &signG, int const &signE);
			AForm(std::string const &name, int const &signG, int const &signE);
			AForm(AForm const &copy);
			virtual ~AForm(void);
		
		//assignment operators
			AForm &operator=(AForm const &copy);
		
		//functions
			void			beSigned(Bureaucrat &src);
			virtual void	execute(Bureaucrat const &executor)const = 0;

		//getters & setters
			std::string const	&getName(void) const;
			bool const			&getIsSigned(void) const;
			int const			&getGradeSign(void) const;
			int const			&getGradeExec(void) const;
		
		//Exceptions
			class GradeTooLowException: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class GradeTooHighException: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class FormNotSignedException: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &str, AForm *form);

# endif