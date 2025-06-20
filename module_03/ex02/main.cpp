#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap clapTrap1;
	ScavTrap scavTrap1;
	FlagTrap flagTrap1;

	std::cout << "===== Attack ===== " << std::endl;
	clapTrap1.attack("other robot");
	scavTrap1.attack("other robor");
	flagTrap1.attack("other robot");

	std::cout << "====================\n" << std::endl;

	std::cout << "===== Take Damage ===== " << std::endl;
	clapTrap1.takeDamage(100);
	scavTrap1.takeDamage(50);
	flagTrap1.takeDamage(50);

	std::cout << "====================\n" << std::endl;

	std::cout << "===== Repair ===== " << std::endl;
	clapTrap1.beRepaired(10);
	scavTrap1.beRepaired(20);
	flagTrap1.beRepaired(30);
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Gate Check ===== " << std::endl;
	scavTrap1.guardGate();
	std::cout << "====================" << std::endl;

	std::cout << "===== High Five===== " << std::endl;
	flagTrap1.highFivesGuys();
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	return (0);
}