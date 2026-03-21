#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &ref)
{
    *this = ref;    
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &ref)
{
    if(this != &ref)
        this->type = ref.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "No Voice" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
