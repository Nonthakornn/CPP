#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat Type";
	std::cout << "Cat Class is constructed" << std::endl;
}

Cat::Cat(const Cat &copy) {
	*this = copy;
}


Cat::~Cat() {
	std::cout << "Cat Class is deconstructed" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string Cat::getType() const {
	return (this->type);
}

void Cat::makeSound() const {
	std::cout << "(Cat make sound) : Meow!" << std::endl;
}