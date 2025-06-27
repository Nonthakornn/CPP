#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Class is constructed" << std::endl;
	this->type = "Cat Type";
	this->cat_brain = new Brain();
}

Cat::Cat(const Cat &copy) {
	this->type = copy.type;
	if (copy.cat_brain)
		this->cat_brain = new Brain(*(copy.cat_brain));
	else
		this->cat_brain = nullptr;
}

Cat::~Cat() {
	std::cout << "Cat Class is deconstructed" << std::endl;
	delete this->cat_brain;
}

Cat& Cat::operator=(const Cat &rhs) {
	std::cout << "Cat Assignment operator called" << std::endl;
	//Self assignment check
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	delete this->cat_brain;
	if (rhs.cat_brain)
		this->cat_brain = new Brain(*(rhs.cat_brain));
	else
		this->cat_brain = nullptr;
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