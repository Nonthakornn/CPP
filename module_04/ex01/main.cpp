#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void subject_main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;
}

void test_deep_copy_dog()
{
	Dog dog;
	Dog dog1(dog);
	Dog dog2;

	std::cout << std::endl;
	std::cout << "===== Before Deep Copy (Dog) =====" << std::endl;
	std::cout << "Dog: " << dog.getIdea(0) << std::endl;
	std::cout << "Dog1: " << dog1.getIdea(0) << std::endl;
	dog.setIdea(0, "eiei");
	std::cout << "===== After Deep Copy ======" << std::endl;
	std::cout << "Dog change to: " << dog.getIdea(0) << std::endl;
	std::cout << "Dog1: " << dog1.getIdea(0) << std::endl;
	std::cout << "====================" << std::endl;

	dog2 = dog;
	std::cout << "dog2 expect to be (eiei): " << dog2.getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
}

void test_deep_copy_cat()
{
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();
	Cat *cat3 = new Cat();

	*cat2 = *cat1;
	std::cout << std::endl;
	std::cout << "===== Before Deep Copy (cat) =====" << std::endl;
	std::cout << "Cat1: " << cat1->getIdea(0) << std::endl;
	std::cout << "Cat2: " << cat2->getIdea(0) << std::endl;
	cat1->setIdea(0, "eiei");
	std::cout << "===== After Deep Copy ======" << std::endl;
	std::cout << "Cat1 change to : " << cat1->getIdea(0) << std::endl;
	std::cout << "Cat2: " << cat2->getIdea(0) << std::endl;
	std::cout << "====================" << std::endl;

	*cat3 = *cat1;
	std::cout << "Cat3 expect to be (eiei): " << cat3->getIdea(0) << std::endl;
	std::cout << std::endl;

	delete cat1;
	delete cat2;
	delete cat3;

	std::cout << std::endl;
}

void fill_array()
{
		Animal* animal_arr[4];

		for (int k = 0; k < 2; k++)
			animal_arr[k] = new Dog();
		for (int l = 2; l < 4; l++)
			animal_arr[l] = new Cat();

		for (int k = 0; k < 2; k++)
			delete animal_arr[k];
		for (int l = 2; l < 4; l++)
			delete animal_arr[l];
}

int main() {
	subject_main();
	test_deep_copy_dog();
	test_deep_copy_cat();
	fill_array();
	return (0);
}