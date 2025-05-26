#include "Weapon.hpp"

Weapon:: Weapon(std::string type):m_type(type) {}

Weapon:: ~Weapon() {}

const std::string& Weapon::getType() const {
	return (this->m_type);
}

void Weapon::setType(std::string set_type) {
	this->m_type = set_type;
}