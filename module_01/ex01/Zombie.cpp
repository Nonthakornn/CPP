#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() {
	std::cout << this->m_name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->m_name << " :BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->m_name = name;
}
