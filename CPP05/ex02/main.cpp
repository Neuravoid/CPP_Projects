#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
int main()
{
	std::srand(std::time(NULL));
	try
	{
		ShrubberyCreationForm ShrubberyForm("Home");
		RobotomyRequestForm RobotomyForm("House");
		PresidentialPardonForm PresidentialForm("What");
		Bureaucrat B1("B1", 2);
		Bureaucrat B2("B2",3);
		B1.signForm(ShrubberyForm);
		B2.signForm(RobotomyForm);
		B2.signForm(PresidentialForm);
		B1.executeForm(ShrubberyForm);
		B2.executeForm(RobotomyForm);
		B1.executeForm(PresidentialForm);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
