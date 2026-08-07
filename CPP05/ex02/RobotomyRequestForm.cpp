#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45, target){
    std::cout << "RobotomyRequestForm Created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), ref.getSignGrade(), ref.getExecGrade(), ref.getTarget()){
    std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
    std::cout << "RobotomyRequestForm Created"<< std::endl;

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref){
    AForm::operator=(ref);
    return *this;
}

void RobotomyRequestForm::action() const{
    std::cout << "Vrrrrrrrrrrrrrrr...." << std::endl;
    bool chance = std::rand() % 2;
    if (chance == 1)
    {
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    }

    else
        std::cout << this->getTarget() << " has been failed." << std::endl;
}