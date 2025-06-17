#include <iostream>

class Base {
private:
	int x;
public:
	Base() {
		std::cout << "Default Base Constructor is called" << std::endl;
	}

	Base(int num): x(num) {
		std::cout << "Parameter Base Constructor is called" << std::endl;
	}

};

class Derived: public Base {
private:
	int y;
public:
	Derived() {
		std::cout << "Default Derived is called" << std::endl;
	}

	Derived(int num): y(num) {
		std::cout << "Parameter Derived Constructor is called" << std::endl;
	}

	//Inherit of Constructure
	Derived(int x, int num): Base(x), y(num) {
		std::cout << "Parameter of Derived" << std::endl;
	}
};

int main(){
	Derived d(20,10);
}
