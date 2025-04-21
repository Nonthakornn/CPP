#include <iostream>

class AbstractEmployee {
	virtual void AskforPromotion() = 0;
};

class Employees:AbstractEmployee {
private:
	std::string Company;
	int Age;
//Any class that inherits from this class (derived classes) can use Name
protected:
	std::string Name;
public:
	std::string get_name() {
		return (Name);
	}

	void display_info() {
		std::cout << "Name: " << Name << std::endl;
		std::cout << "Company: " << Company << std::endl;
		std::cout << "Age: " << Age << std::endl;
	}

	Employees(std::string name, std::string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}

	void AskforPromotion() {
		if (Age > 20)
			std::cout << "You get Promote!" << std::endl;
		else
			std::cout << "No!!" << std::endl;
	}

	virtual void Work() {
		std::cout << Name << " is doing something" << std::endl;
	}
};

class Developer: public Employees {
public:
	std::string Language;
	Developer(std::string name, std::string company, int age, std::string lang)
	:Employees(name, company, age) {
		Language = lang;
	}
	void display_dev_info() {
		// std::cout << "Name: " << get_name() << std::endl;

		//Use protected instead
		std::cout << "Name: " << Name << std::endl;
		std::cout << "Programming Language: " << Language << std::endl;
	}
	void Work() {
		std::cout << Name << " is Writing " << Language << std::endl;
	}
};


int main()
{
	Developer dev1 = Developer("Suzy", "Microsoft", 25, "Python");
	// dev1.display_dev_info();
	// dev1.AskforPromotion();
	// dev1.Work();

	Employees *e = &dev1;
	e->Work();
}
