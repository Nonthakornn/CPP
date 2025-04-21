#include <iostream>

class Employee {
private:
	std::string Name;
	std::string Company;
	int Age;
public:

	void set_name(std::string name) {
		Name = name;
	}

	std::string get_name() {
		return Name;
	}

	void display_info() {
		std::cout << "Name: " << Name << std::endl;
		std::cout << "Company: " << Company << std::endl;
		std::cout << "Age: " << Age << std::endl;
	}

	Employee (std::string name, std::string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
};

int main()
{
	Employee em1 = Employee("em1", "Google", 12);
	em1.display_info();
	/*
	We cannot display this if we change it to private
	std::cout << em1.Name << std::endl;
	*/
	em1.set_name("John");
	std::cout << "Changed Name to: " << em1.get_name() << std::endl;
	em1.display_info();
}