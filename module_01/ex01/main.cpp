#include "Zombie.hpp" 

int main()
{
	Zombie *horde_zombie;
	horde_zombie = zombieHorde(5, "UnamedZombie");
	for (int i = 0; i < 5; i++) {
		std::cout << "Index[" << i  << "]: ";
		horde_zombie[i].announce();
	}
	delete[] horde_zombie;
}
