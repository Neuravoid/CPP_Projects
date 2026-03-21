#include <string>
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &Name, Weapon &weapon){
    this->name = Name;
    this->weapon = &weapon;
}

void HumanA::attack()
{
    std::cout << this->name+" attacks with their "+this->weapon->getType() << std::endl;
}
HumanA::~HumanA() {}