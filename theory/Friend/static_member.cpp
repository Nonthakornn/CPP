#include <iostream>

class Test {
private:
	int a;
	int b;
public:
	static int count; //It share memory

	Test(){
		a = 10;
		b = 10;
		count++;
	}

	static int getCount()
	{
		return (count); // They can only access a static member only
	}
};

int Test::count = 0;

int main()
{
	Test t1;
	Test t2;

	std::cout << t1.count << std::endl; //2
	std::cout << t2.count << std::endl; //2
	std::cout << Test::count << std::endl; //2
}