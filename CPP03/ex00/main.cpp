#include "ClapTrap.hpp"
#include <iostream>
int main()
{
	std::cout << "--- Creating ClapTraps ---" << std::endl;
	ClapTrap clippy("Clippy");
	ClapTrap trappy("Trappy");

	std::cout << "\n--- Basic Actions ---" << std::endl;
	clippy.attack("Trappy");
	trappy.takeDamage(0);
	trappy.beRepaired(5);

	std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
	for (int i = 0; i < 11; i++) {
		clippy.attack("a poor target");
	}

	std::cout << "\n--- Testing Damage and Death ---" << std::endl;
	trappy.takeDamage(20); // Should reach 0 HP
	trappy.attack("Clippy"); // Should fail due to no HP
	trappy.beRepaired(10); // Should fail due to no HP

	std::cout << "\n--- Copying a ClapTrap ---" << std::endl;
	ClapTrap copy(clippy);
	ClapTrap assigned;
	assigned = trappy;

	std::cout << "\n--- End of Main ---" << std::endl;
	return 0;
}