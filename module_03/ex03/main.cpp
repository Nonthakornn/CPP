#include "DiamondTrap.hpp"

int main() {

	DiamondTrap dia;
	DiamondTrap dia2("dia2-robot");

	std::cout << "===== Attack ===== " << std::endl;
	dia.attack("others");
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Take Damage ===== " << std::endl;
	dia.takeDamage(20);

	std::cout << "====================\n" << std::endl;

	std::cout << "===== Repair ===== " << std::endl;
	dia.beRepaired(20);
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Gate Check ===== " << std::endl;
	dia.guardGate();
	dia.guardGate();
	std::cout << "====================\n" << std::endl;

	std::cout << "===== High Five===== " << std::endl;
	dia.highFivesGuys();
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Who am I===== " << std::endl;
	dia.whoAmI();
	dia2.whoAmI();
	std::cout << "====================\n" << std::endl;
	std::cout << std::endl;
	return (0);
}