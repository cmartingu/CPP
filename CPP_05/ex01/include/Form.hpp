#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
			std::string const	name;
			bool				isSigned;
			int	const			gradeSign;
			int const			gradeExec;
	public:
		//constructors & destructors
			Form(void);
			Form(std::string const &name);
			Form(int const &signG, int const &signE);
			Form(std::string const &name, int const &signG, int const &signE);
			Form(Form const &copy);
			~Form(void);
		
		//assignment operators
			Form &operator=(Form const &copy);
		
		//functions
			void	beSigned(Bureaucrat &src);

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
};

std::ostream	&operator<<(std::ostream &str, Form *form);

# endif