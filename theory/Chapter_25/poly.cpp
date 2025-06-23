#include <iostream>

using namespace std;

class Car {
public:
	// virtual void start() {
	// 	cout << "Car Stated" << endl;
	// }

	// virtual void stop() {
	// 	cout << "Car Stopped" << endl;
	// }

	//pure
	virtual void start() = 0;
	virtual void stop() = 0;
};

class Innova : public Car {
public:
	void start() {
		cout << "Innova Stated" << endl;
	}

	void stop() {
		cout << "Innova Stopped" << endl;
	}
};

class Swift: public Car {
public:
	void start() {
		cout << "Swift Stated" << endl;
	}

	void stop() {
		cout << "Swift Stopped" << endl;
	}
};

int main() {
	Car *c = new Innova();
	c->start();

	c = new Swift();
	c->start();

}