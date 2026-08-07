#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

static void checkGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name("No Name"), grade(75)
{
	std::cout << "Bureaucrat created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	checkGrade(grade);
	std::cout << "Bureaucrat created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.getName()), grade(ref.getGrade())
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}

void Bureaucrat::signForm(Form& form){
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}
