#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Creating FragTrap ---" << std::endl;
	FragTrap frag("Fraggy");

	std::cout << "\n--- Basic FragTrap Actions ---" << std::endl;
	frag.attack("someone");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();

	std::cout << "\n--- Testing Copy Construction and Assignment ---" << std::endl;
	FragTrap fragCopy(frag);
	FragTrap fragAssigned;
	fragAssigned = frag;
	fragAssigned.highFivesGuys();

	std::cout << "\n--- End of Main (Destructors Call) ---" << std::endl;
	return 0;
}