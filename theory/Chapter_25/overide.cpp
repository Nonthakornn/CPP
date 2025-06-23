#include <iostream>

using namespace std;

class Parent {
private:
public:
	virtual void display() {
		cout << "Display parent" << endl;
	}
};

class Child : public Parent {
public:
	void display() {
		cout << "Display Child" << endl;
	}
};

int main() {
	// Parent *p = new Child();
	// p->display();
	Child c;
	c.display();
}