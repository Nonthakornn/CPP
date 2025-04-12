#include <iostream>

using namespace std;

class Person {
public:
	//Attributes
	string name;
	int age;

	//Constructor
	Person(string n, int a) : name(n), age(a) {}

	//Method
	void greet() const {
		cout << "Hello, my name is " << name << " I'm " << age << "years old.";
	}
};

int main()
{
	Person person1("Alice", 30);
	person1.greet();
}