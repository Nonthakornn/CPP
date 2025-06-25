#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Class is constructed" << std::endl;
	this->type = "Dog Type";
	this->dog_brain = new Brain();
}

Dog::Dog(const Dog &copy) {
	this->type = copy.type;
	this->dog_brain = new Brain();
}

Dog::~Dog() {
	delete this->dog_brain;
	std::cout << "Dog Class is deconstructed" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs) {
	this->type = rhs.type;
	if (this->dog_brain)
		delete (this->dog_brain);
	this->dog_brain = new Brain();
	return (*this);
}

std::string Dog::getType() const {
	return (this->type);
}

void Dog::makeSound() const {
	std::cout << "(Dog make sound) : Barkk!" << std::endl;
}

std::string Dog::getIdea(int num) {
	std::cout << "Adress:" << &this->dog_brain->idea[num] << std::endl;
	return (this->dog_brain->idea[num]);
}

void Dog::setIdea(int num, std::string new_idea)
{
	this->dog_brain->idea[num] = new_idea;
}