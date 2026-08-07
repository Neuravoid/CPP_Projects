#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Standart Form"), isSigned(0), signGrade(100), execGrade(50){
    
};

Form::Form(const std::string name, const int signGrade, const int execGrade) : name(name), isSigned(0), signGrade(signGrade), execGrade(execGrade){

};

Form::~Form(){

};

Form& Form::operator=(const Form& rs){
    this->isSigned = rs.getIsSigned();
    return *this;
}

Form::Form(const Form &ref) : name(ref.getName()), isSigned(ref.getIsSigned()), signGrade(ref.getSignGrade()),  execGrade(ref.getExecGrade()){
    
};

std::string Form::getName() const{
    return(this->name);
};

int Form::getSignGrade() const{
    return(this->signGrade);
};

bool Form::getIsSigned() const{
    return(this->isSigned);
};

int Form::getExecGrade() const{
    return(this->execGrade);
};

const char* Form::GradeTooHighException::what() const throw(){
    const char* msg  = "This Grade To High!";
    return(msg);
}

const char* Form::GradeTooLowException::what() const throw(){
    const char* msg  = "This Grade To Low!";
    return(msg);
}

const char* Form::AlreadySignedException::what() const throw(){
    const char* msg  = "This Form Already Signed by This Bureaucrat";
    return(msg);
}

void Form::beSigned(const Bureaucrat& ref)
{
	if (this->getSignGrade() >= ref.getGrade())
    {
        std::cout << ref.getName() << " signed " << this->getName() << std::endl;
		this->isSigned = 1;
    }
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Form& ref)
{
	out << ref.getName() << ", Form Sign Grade: " << ref.getSignGrade() << " Form Execution Grade: " << ref.getExecGrade() << " ." << std::endl;
	return out;
}