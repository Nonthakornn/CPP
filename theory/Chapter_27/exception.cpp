#include <iostream>

int main()
{
	int a = 10, b = 5, c;

	try {
		if (b == 0)
			throw -1;
	c = a / b;
	std::cout << c << std::endl;
	}
	catch(int e){
		std::cout << "Division by zero ->  " << "error code: "  << e << std::endl;
	}
}