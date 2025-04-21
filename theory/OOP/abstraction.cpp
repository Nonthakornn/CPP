#include <iostream>

/*
Simplifying complex systems by modeling classes based on their 
essential properties, while hiding unnecessary details. 
This helps manage complexity by focusing on what an object does rather than how it does it.
*/

// pure virtual function
class AbstractEmployee {
	virtual void AskforPromotion() = 0;
};

class Employees:AbstractEmployee {
private:
	std::string Name;
	std::string Company;
	int Age;
public:
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
		if (Age >= 30)
			std::cout << "You get promoted!" << std::endl;
		else
			std::cout << "No promotion for you!" << std::endl;
	}
};

int main()
{
	Employees em1 = Employees("John", "Google", 25);
	Employees em2 = Employees("Brian", "Tesla", 30);

	// em1.AskforPromotion();
	// em2.AskforPromotion();
}
