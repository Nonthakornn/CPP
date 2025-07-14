#include <iostream>

class MyException {

};

int divide(int a, int b) {

	if (b == 0)
		throw MyException();
	return a / b;
}

int main() {
	int a = 20 , b = 0 , c;

	try {
		c = divide(a, b);
		std::cout << c;
	}
	catch(MyException e)
	{
		std::cout << "Error" << std::endl;
	}
	catch(int e)
	{

	}
	catch(float e) {

	}
	catch (...) { //Catch All
	}
}