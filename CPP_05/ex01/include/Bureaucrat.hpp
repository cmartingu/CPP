#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
			std::string const	name;
			int					grade;
	public:
		//constructors & destructors
			Bureaucrat(void);
			Bureaucrat(const int &grade);
			Bureaucrat(std::string const &name);
			Bureaucrat(std::string const &name, const int &grade);
			Bureaucrat(Bureaucrat const &copy);
			~Bureaucrat(void);
		
		//assignment operators
			Bureaucrat &operator=(Bureaucrat const &copy);

		//functions
			void	incrementGrade(void);
			void	decrementGrade(void);
			void	signForm(Form &form);

		//getters & setters
			std::string const	&getName(void) const;
			int const			&getGrade(void) const;
			void				setGrade(int const &grade);
		
		//Exceptions
			class GradeTooHighException: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class GradeTooLowException: public std::exception
			{
				public:
					virtual const char *what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat *src);

# endif