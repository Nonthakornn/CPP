#include "easyfind.hpp"

void test_with_number();
void test_with_string();

int main()
{
	test_with_number();
	test_with_string();
}

void test_with_number() {
	try 
	{
		std::vector<int> v;

		v.push_back(0);
		v.push_back(1);
		v.push_back(3);
		v.push_back(1);

		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Value Found at index: " << *it << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << "Exception Caught: " << e.what() << std::endl;
	}

}

void test_with_string() {
	try{
		std::vector<std::string> str;

		str.push_back("One");
		str.push_back("Two");
		str.push_back("One");
		str.push_back("Four");

		std::vector<std::string>::iterator it = easyfind(str, "One");
		// std::vector<std::string>::iterator it = easyfind(str, "Onex");
		std::cout << "Founded: " << *it << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << "Exception Caught: " << e.what() << std::endl;
	}

}