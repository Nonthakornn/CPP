#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Class is constructed" << std::endl;
	this->type = "Dog Type";
	this->dog_brain = new Brain();
}

Dog::Dog(const Dog &copy) {
	this->type = copy.type;
	if (copy.dog_brain)	
		this->dog_brain = new Brain(*(copy.dog_brain));
	else
		this->dog_brain = nullptr;
}

Dog::~Dog() {
	std::cout << "Dog Class is deconstructed" << std::endl;
	delete this->dog_brain;
}

Dog& Dog::operator=(const Dog &rhs) {
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	delete this->dog_brain;
	if (rhs.dog_brain)
		this->dog_brain = new Brain(*(rhs.dog_brain));
	else
		this->dog_brain = nullptr;
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