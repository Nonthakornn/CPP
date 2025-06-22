#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap clapTrap1("ct1");
	ScavTrap scavTrap1("st1");
	FragTrap fragTrap1("ft1");

	std::cout << "===== Attack ===== " << std::endl;
	clapTrap1.attack("other robot");
	scavTrap1.attack("other robor");
	fragTrap1.attack("other robot");

	std::cout << "====================\n" << std::endl;

	std::cout << "===== Take Damage ===== " << std::endl;
	clapTrap1.takeDamage(100);
	scavTrap1.takeDamage(50);
	fragTrap1.takeDamage(50);

	std::cout << "====================\n" << std::endl;

	std::cout << "===== Repair ===== " << std::endl;
	clapTrap1.beRepaired(10);
	scavTrap1.beRepaired(20);
	fragTrap1.beRepaired(30);
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Gate Check ===== " << std::endl;
	scavTrap1.guardGate();
	std::cout << "====================" << std::endl;

	std::cout << "===== High Five===== " << std::endl;
	fragTrap1.highFivesGuys();
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	return (0);
}