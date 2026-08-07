#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern& operator=(Intern& ref);
		Intern(Intern& ref);

		AForm *makeForm(std::string formName, std::string target);
};

#endif
