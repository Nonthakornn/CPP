#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal Type";
	std::cout << "WrongAnimal Class is constructed" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Class is deconstructed" << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::makeSound() const {
	std::cout << "(WrongAnimal make sound) : zzzZZZ!" << std::endl;
}
