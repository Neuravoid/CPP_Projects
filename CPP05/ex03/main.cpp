#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern i1;
	AForm* f1 = i1.makeForm("presidentialpardon form","home");
	std::cout << f1->getTarget() << std::endl;
	delete f1;
	return 0;
}
