#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(){
    this->name = "Undefined";
    this->weapon = NULL;
}

HumanB::HumanB(const std::string Name){
    this->name = Name;
    this->weapon = NULL;
}

HumanB::HumanB(const std::string Name, Weapon *weapon){
    this->name = Name;
    this->weapon = weapon;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    this->weapon = &newWeapon;
}

void HumanB::attack()
{
    std::cout << this->name+" attacks with their "+this->weapon->getType() << std::endl;
}

HumanB::~HumanB() {}