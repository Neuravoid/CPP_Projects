#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "FragTrap: Default Name";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: Default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: Default name constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &Trap)
{
    if (this != &Trap)
        ClapTrap::operator=(Trap);
    std::cout << "FragTrap: Copy assignment operator called" << std::endl;
    return(*this);
}

FragTrap::FragTrap(const FragTrap& Trap) : ClapTrap(Trap)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: " << this->_name << " wants to give you a high five!" << std::endl;
}