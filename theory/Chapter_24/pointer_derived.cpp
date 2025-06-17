#include <iostream>

class Base
{
public:
	void func1() {
		std::cout << "func1 called" << std::endl;
	}
};

class Derived: public Base
{
public:
	void func2(){
		std::cout << "fun2 called" << std::endl;
	}
};

int main()
{
	Derived d;
	Base *ptr = &d;
	ptr->func1();
	// ptr->func12(); Cannot access Derived class
}