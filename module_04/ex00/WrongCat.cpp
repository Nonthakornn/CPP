#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat Type";
	std::cout << "WrongCat Class is constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Class is deconstructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string WrongCat::getType() const {
	return (this->type);
}

void WrongCat::makeSound() const {
	std::cout << "(WrongCat make sound) : Meow!" << std::endl;
}