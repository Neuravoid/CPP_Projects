#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "PresidentialPardonForm Created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm Destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade(), ref.getTarget()){
    std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
    std::cout << "PresidentialPardonForm Created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref){
    AForm::operator=(ref);
    return *this;
}   

void PresidentialPardonForm::action() const{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}