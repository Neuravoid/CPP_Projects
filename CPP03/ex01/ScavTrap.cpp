#include "ScavTrap.hpp"
#include <iostream>
#include <string>


ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "ScavTrap: Default Name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &Trap) : ClapTrap(Trap)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &Trap)
{
	if (this != &Trap)
	{
		ClapTrap::operator=(Trap);
	}
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	return *this;
} 

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no hit points or energy points left!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}