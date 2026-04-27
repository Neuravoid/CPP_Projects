#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){

}

Bureaucrat::~Bureaucrat(){

}

Bureaucrat::Bureaucrat(const Bureaucrat &var){

}

Bureaucrat& const Bureaucrat::operator=(Bureaucrat& var){

}

void Bureaucrat::operator<<(const Bureaucrat &var){

}

int Bureaucrat::getGrade()
{
	return(this->grade);
}

std::string Bureaucrat::getName()
{
	return(this->name);
}

