#include "ClapTrap.hpp"

int main() {
	ClapTrap robot;
	ClapTrap robot1("Robot-1");
	ClapTrap robot2("Robot-2", 0, 15, 10);
	ClapTrap robot3("Robot-3", 10, 0, 10);

	std::cout << "Attack: " << std::endl;
	robot.attack("Other Robot");
	robot1.attack("Other Robot");
	robot2.attack("Other Robot");
	robot3.attack("Other Robot");

	std::cout << "\nTake Damage: " << std::endl;
	robot.takeDamage(5);
	robot1.takeDamage(10);
	robot1.takeDamage(10);
	robot2.takeDamage(10);
	robot3.takeDamage(10);

	std::cout << "\nRepair: " << std::endl;
	robot.beRepaired(5);
	robot1.beRepaired(10);
	robot1.beRepaired(10);
	robot2.beRepaired(10);
	robot3.beRepaired(10);
	std::cout << std::endl;

	return (0);
}