#include "Weapon.hpp"

Weapon::Weapon(){
    this->type = " ";
}

Weapon::Weapon(const std::string &newType){
    this->type = newType;
}


Weapon::~Weapon(){
    
}

const std::string &Weapon::getType(){
    return(this->type);
}

void Weapon::setType(const std::string &ref)
{
    this->type = ref;
}

