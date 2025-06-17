#include <iostream>

class Rectangle {
private:
	int lenght;
	int breath;
public:
	Rectangle():lenght(0), breath(0) {};
	Rectangle(int l, int b): lenght(l), breath(b){};

	int		getLength() { return (this->lenght); }
	int		getBreath() { return (this->breath); } 
	void	setLength(int l) { this->lenght = l; }
	void	setBreath(int b) {this->breath = b; }
	int		area() { return (this->breath * this->lenght ); }
	int		perimeter() {return (2 * (this->lenght +  this->breath)); }
};

class Cuboid: public Rectangle {
private:
	int height;
public:
	Cuboid(int l = 0, int b = 0, int h = 0) {
		height = h;
		//Inherit from Rectangle calss
		setLength(l);
		setBreath(l);
	}

	int getHeight() { return this->height; }
	void setHeight(int h) { this->height = h ; }
	int volume () { return (getLength() * getBreath() * height); }
};

int main()
{
	Rectangle r1(5 ,2);
	std::cout << r1.area() << std::endl;

	Cuboid c(10,5,3);
	std::cout << c.getLength() << std::endl;
	std::cout << c.volume() << std::endl;
}

/*
class Base {
private:
	int a;

protected:
	int b;

public:
	int c;

	void funcBase() {
		a = 10;
		b = 20;
		c = 30;
	}
};

class Derived: public Base {
public:
	void funcDerived() {
		// Can access only procted and public
		b = 2;
		c = 3;
	}
};

int main() {
	Base x; // you cannot access private and protected
}
*/