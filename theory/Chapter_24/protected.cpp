#include <iostream>

class Parent {
private:
	int a;
protected:
	int b;
public:
	int c;

	void funParent()
	{
		a = 10;
		b = 20;
		c = 30;
	}
};

class Child: public Parent {
private:
protected:
public:
	void funChild()
	{
		// a = 12; 
		b = 5;
		c = 10;
	}
};

class GrandChild: public Child 
{
public:
	void funGrandChild()
	{
		// a = 10;
		// b = 5;
		// c = 12;
	}
};

int main()
{
	Child c;
	// c.a = 10;
	// c.b = 20;
	// c.c = 20;
}