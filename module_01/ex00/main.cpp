#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = newZombie("Heap Zombie");
	zombie->announce();
	delete zombie;
	randomChump("Stack Zombie");
}
