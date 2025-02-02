#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class AForm;

class Intern
{
    public:
        //Constructors & destructors
            Intern(void);
            Intern(Intern const &copy);
            ~Intern(void);

        //assignment operators
            Intern &operator=(Intern const &copy);
        
        //public methods
            AForm    *makeForm(std::string const form, std::string const target);
};

#endif