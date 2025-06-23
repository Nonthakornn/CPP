#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog Type";
	std::cout << "Dog Class is constructed" << std::endl;
}

Dog::Dog(const Dog &copy) {
	*this = copy;
}


Dog::~Dog() {
	std::cout << "Dog Class is deconstructed" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string Dog::getType() const {
	return (this->type);
}

void Dog::makeSound() const {
	std::cout << "(Dog make sound) : Barkk!" << std::endl;
}