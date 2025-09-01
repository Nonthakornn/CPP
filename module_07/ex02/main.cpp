#include "Array.hpp"

void test_default_constructor();
void test_parameter_constructor();
void test_copy_constructor();

int main()
{
	// test_default_constructor();
	// test_parameter_constructor();
	test_copy_constructor();
}

void test_default_constructor() {
	Array<int> A;
	std::cout << "Type Info of A: " << typeid(A).name() << std::endl;
	Array<std::string> B;
	std::cout << "Type Info of B: " << typeid(B).name() << std::endl;
	Array<float> C;
	std::cout << "Type Info of C: " << typeid(C).name() << std::endl;
}

void test_parameter_constructor() {
	Array<int> A(5);
	std::cout << A.size() << std::endl;
	Array<std::string> B(3);
	std::cout << B.size() << std::endl;
}

void test_copy_constructor() {
	Array<int> A(5);
	Array<int> B(A);
	Array<int> C;
	B = C;
}