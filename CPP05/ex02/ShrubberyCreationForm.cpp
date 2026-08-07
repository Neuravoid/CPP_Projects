#include "ShrubberyCreationForm.hpp"
#include <fstream>

const char* ShrubberyCreationForm::FileException::what() const throw(){
    const char* msg = "File couldn't open.";
    return(msg);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145 , 137, target){
    std::cout << "ShrubberyCreationForm Created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref){
    AForm::operator=(ref);
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref): AForm(ref.getName(),ref.getSignGrade(),ref.getExecGrade(),ref.getTarget()){
    std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
    std::cout << "ShrubberyCreationForm Created" << std::endl;
}

void ShrubberyCreationForm::createTree(int n, char c, std::ofstream& file) const{
    int level = 1;
    while (level <= n)
    {  
       int space = n - level - 1;
       std::string spaceString(space / 2, ' ');
       std::string treeString(level, c);
       file << spaceString+treeString+spaceString << std::endl; 
       level++;
    }
    std::string woodString(2, '|');
    std::string spaceString((n-1) / 2, ' ');
    file << spaceString+woodString+spaceString << std::endl;
    file << spaceString+woodString+spaceString;
    
}

void ShrubberyCreationForm::action() const{
    std::string fileName = this->getTarget()+"_shrubbery";
    const char* path = fileName.c_str();
    std::ofstream file(path);
    if (file.is_open())
        createTree(8, '*', file);
    else
        throw FileException();
}

