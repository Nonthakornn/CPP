#include <iostream>

class Test {
private:
	int a;
protected:
	int b;
public:
	int c;

friend void func();
};

void func(){
	Test t;

	t.a = 5; //Normally we cannot access this but we use friend
	t.b = 4; // Normally we cannot access this
	t.c = 6;
}