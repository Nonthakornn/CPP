#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	Dog dog;
	Dog dog1(dog);

	// Animal animal_arr[4];

	std::cout << std::endl;
	std::cout << "===== Before Deep Copy =====" << std::endl;
	std::cout << "Dog: " << dog.getIdea(0) << std::endl;
	std::cout << "Dog1: " << dog1.getIdea(0) << std::endl;
	dog.setIdea(0, "eiei");
	std::cout << "===== After Deep Copy ======" << std::endl;
	std::cout << "Dog: " << dog.getIdea(0) << std::endl;
	std::cout << "Dog1: " << dog1.getIdea(0) << std::endl;
	std::cout << "====================" << std::endl;

	std::cout << std::endl;
	// delete dog;
	// delete cat;
}