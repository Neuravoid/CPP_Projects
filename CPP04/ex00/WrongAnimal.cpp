#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
    *this = ref;    
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref)
{
    if(this != &ref)
        this->type = ref.type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "No Voice" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
