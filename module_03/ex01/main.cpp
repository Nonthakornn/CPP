#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
Inherit can access base public function but not private members
*/

int main() {
	ScavTrap robot1;
	ScavTrap robot2("Robot2");
	ScavTrap robot3("Robot3", 5, 5, 0);

	for (int i = 0; i <= 5; i++)
	{
		robot3.takeDamage(1);
	}
	std::cout << std::endl;
	robot1.guardGate();
	robot3.guardGate();
	return (0);
}