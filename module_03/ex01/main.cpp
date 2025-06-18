#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap robot1;
	ScavTrap robot2("Robot_2");
	ScavTrap robot3 = robot1;


	std::cout << "===== Attack ===== " << std::endl;
	robot1.attack("other robot");
	robot2.attack("other robot");
	robot3.attack("other robot");
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Take Damage ===== " << std::endl;
	for (int i = 0; i <= 5; i++)
		robot1.takeDamage(50);
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Repair ===== " << std::endl;
	robot1.beRepaired(20);
	robot2.beRepaired(20);
	robot3.beRepaired(20);
	std::cout << "====================\n" << std::endl;

	std::cout << "===== Gate Check ===== " << std::endl;
	robot1.guardGate();
	robot1.guardGate();
	robot2.guardGate();
	robot2.guardGate();
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	return (0);
}