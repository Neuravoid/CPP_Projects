#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern Created" << std::endl;
}

Intern::~Intern(){
    std::cout << "Intern Destroyed" << std::endl;
}

Intern::Intern(Intern &ref){
    *this = ref;
    std::cout << "Intern Copy Constructor Called" << std::endl;
    std::cout << "Intern Created" << std::endl;

}

Intern& Intern::operator=(Intern& ref){
    return ref;
}

static std::string stringLower(std::string ref){
    int i = 0;
    while (ref[i])
    {
        if (ref[i] <= 'Z' && ref[i] >= 'A')
        {
            ref[i] = ref[i] + 32;
        }
        i++;
    }
    return ref;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string  nameList[3] = {"presidentialpardon form", "shrubberycreation form", "robotomyrequest form"};
    AForm* f1 = new PresidentialPardonForm(target);
    AForm* f2 = new ShrubberyCreationForm(target);
    AForm* f3 = new RobotomyRequestForm(target);
    AForm* classList[3] = {f1,f2,f3};
    int i = 0;

    while (nameList[i].compare(stringLower(formName)) != 0)
        i++;

    
    i = 0;
    int j = 0;
    while (j < 3)
    {
        if (i != j)
            delete classList[j];        
        j++;
    }
    return classList[i];
}