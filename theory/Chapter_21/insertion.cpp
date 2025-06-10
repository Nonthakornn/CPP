#include <iostream>

class Person {
public:
	std::string m_name;
	int m_age;
	Person(std::string name , int age) :m_name(name), m_age(age) {};

};

std::ostream& operator<<(std::ostream& out, Person &p1) {
	out << p1.m_name;
	out << p1.m_age;
	return (out);
}

int main() {
	Person p1("Mike", 20);
	std::cout << p1 << std::endl;

}