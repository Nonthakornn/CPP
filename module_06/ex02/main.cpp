#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int choice = rand() % 3;
	if (choice == 0) {
		return new A();
	} else if (choice == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception& e) {}
	
	std::cout << "C" << std::endl;
}

int main() {
	{
		srand(time(NULL));

		Base* myObject = generate();

		std::cout << "Identifying pointer: ";
		identify(myObject);

		std::cout << "Identifying reference: ";
		identify(*myObject);

		delete myObject;
	}

	{
		srand(time(NULL));
		std::cout << "--- Testing with 10 random instances ---" << std::endl;

		for (int i = 0; i < 10; ++i) {
			Base* ptr = generate();
			
			std::cout << "Instance " << i + 1 << ": ";
			std::cout << "Pointer identify: ";
			identify(ptr);

			std::cout << "Reference identify: ";
			identify(*ptr);

			delete ptr;
			std::cout << "--------------------" << std::endl;
		}
	}
	
	return 0;
}