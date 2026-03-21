#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Creating ClapTrap ---" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("a target");

	std::cout << "\n--- Creating ScavTrap ---" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("target A");
	scav.beRepaired(10);
	scav.takeDamage(30);
	scav.guardGate();

	std::cout << "\n--- Testing Copy Construction ---" << std::endl;
	ScavTrap scavCopy(scav);
	scavCopy.attack("target B");

	std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	ScavTrap scavAssigned;
	scavAssigned = scav;
	scavAssigned.guardGate();

	std::cout << "\n--- Destructors will call now ---" << std::endl;
	return 0;
}