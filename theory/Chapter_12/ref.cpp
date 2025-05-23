#include <iostream>

void increment(int& value) {
	value++;
}

int main()
{
	int x = 5;
	int y = 9;
	int& ref = x; //it is like an alias of x

	std::cout << x << std::endl;
	increment(x);
	std::cout << x << std::endl;
	increment(ref);
	std::cout << ref << std::endl;

	ref = y; // x will change to 9 , y = 9

}
