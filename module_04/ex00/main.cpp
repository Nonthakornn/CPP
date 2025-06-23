#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n======== Wrong Test ==========" << std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();
	
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	wrong->makeSound();
	wcat->makeSound();

	delete wrong;
	delete wcat;

	std::cout << "\n============================" << std::endl;

}