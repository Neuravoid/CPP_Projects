#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), isSigned(0), signGrade(100), execGrade(50), target("AForm"){
    std::cout << "AForm Created" << std::endl;
};

AForm::AForm(const std::string name, const int signGrade, const int execGrade, const std::string target) : name(name), isSigned(0), signGrade(signGrade), execGrade(execGrade), target(target){
    std::cout << "AForm Created" << std::endl;
};

AForm::~AForm(){
    std::cout << "AForm Destroyed" << std::endl;
};

AForm& AForm::operator=(const AForm& rs){
    this->isSigned = rs.getIsSigned();
    this->target = rs.getTarget();
    return *this;
}

AForm::AForm(const AForm &ref) : name(ref.getName()), isSigned(ref.getIsSigned()), signGrade(ref.getSignGrade()),  execGrade(ref.getExecGrade()),   target(ref.getTarget()){

};

std::string AForm::getName() const{
    return(this->name);
};

int AForm::getSignGrade() const{
    return(this->signGrade);
};

bool AForm::getIsSigned() const{
    return(this->isSigned);
};

int AForm::getExecGrade() const{
    return(this->execGrade);
};

AForm::GradeException::GradeException(const char *msg){
    this->msg = msg;
}


const char* AForm::GradeException::what() const throw()
{
    return this->msg;
}

void AForm::beSigned(const Bureaucrat& ref)
{
	if (this->getSignGrade() >= ref.getGrade())
    {
        std::cout << ref.getName() << " signed " << this->getName() << std::endl;
		this->isSigned = 1;
    }
	else
		throw AForm::GradeException("This Grade Too Low To Sign!");
}

void AForm::execute(const Bureaucrat& ref) const
{
    if (this->getIsSigned() != 1)
		throw AForm::GradeException("This Grade Too Low To Sign!");
    if (ref.getGrade() > this->getExecGrade())
        throw AForm::GradeException("This Grade Too Low To Execute!");
    this->action();
}

const std::string AForm::getTarget() const{
    return this->target;
}

std::ostream& operator<<(std::ostream& out, AForm& ref)
{
	out << ref.getName() << ", Form Sign Grade: " << ref.getSignGrade() << " Form Execution Grade: " << ref.getExecGrade() << " ." << std::endl;
	return out;
}
