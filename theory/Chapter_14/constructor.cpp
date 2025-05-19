#include <iostream>

class Foo {
private:
	int _x{};
	int _y{};

public:
	Foo(int x, int y);
	void print();

};

Foo::Foo(int x , int y)
	: _x {x}
	, _y {y} {
	std::cout << "Foo: " << x << ", " << y << " has constructed" << std::endl;
}

void Foo::print()
{
	std::cout << "x: " << _x << " y:" << _y << std::endl;
}

int main()
{
	Foo foo{5, 6};
	foo.print();
}
