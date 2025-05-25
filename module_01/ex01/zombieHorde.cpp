#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *new_zombie;

	new_zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		new_zombie[i].set_name(name);
	return (new_zombie);
}

/*
Zombie *zombieHorde(int N, std::string name) {
	Zombie *new_zombie;
	new_zombie = new Zombie[N];

	for (int i = 0; i < N; i++) {
		Creating a new temporary Zombie object with the name
		Assigning it to the array element (which copies the data)
		Destroying the temporary object immediately afterward
		so we dont need to make a new constructor Zombie(std::string naem)
		
		new_zombie[i] = Zombie(name);
	}
	return (new_zombie);
}
*/