#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal Type";
	std::cout << "Animal Class is constructed" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Class is deconstructed" << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;
}

Animal& Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::makeSound() const {
	std::cout << "(Animal make sound) : zzzZZZ!" << std::endl;
}
