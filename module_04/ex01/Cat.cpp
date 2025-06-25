#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Class is constructed" << std::endl;
	this->type = "Cat Type";
	this->cat_brain = new Brain();
}

Cat::Cat(const Cat &copy) {
	this->type = copy.type;
	this->cat_brain = new Brain();
}

Cat::~Cat() {
	delete this->cat_brain;
	std::cout << "Cat Class is deconstructed" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs) {
	this->type = rhs.type;
	if (this->cat_brain)
		delete cat_brain;
	this->cat_brain = new Brain();
	return (*this);
}

std::string Cat::getType() const {
	return (this->type);
}

void Cat::makeSound() const {
	std::cout << "(Cat make sound) : Meow!" << std::endl;
}

std::string Cat::getIdea(int num) {
	std::cout << "Adress:" << &this->cat_brain->idea[num] << std::endl;
	return (this->cat_brain->idea[num]);
}

void Cat::setIdea(int num, std::string new_idea)
{
	this->cat_brain->idea[num] = new_idea;
}