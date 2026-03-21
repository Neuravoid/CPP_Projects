#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &Trap);
	ScavTrap& operator=(const ScavTrap &Trap);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};

#endif 