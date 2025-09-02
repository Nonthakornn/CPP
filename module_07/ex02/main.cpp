#include "Array.hpp"

void test_default_constructor();
void test_parameter_constructor();
void test_copy_constructor();
void test_overflow();
void test_overflow_pointer();
void test_deep_copy();

int main()
{
	test_default_constructor();
	test_parameter_constructor();
	test_copy_constructor();
	test_overflow();
	test_overflow_pointer();
	test_deep_copy();
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

void test_overflow() {
	try {
		std::cout << "====== Before ======" << std::endl;
		Array<int> A(6);
		A.print();
		A.setIndex(2, 9999);
		std::cout << "====== After ======" << std::endl;
		A.print();

		std::cout << "Array at Index 2: " << A[2] <<  std::endl;
		std::cout << "Array at Out of bound: " << A[6] <<  std::endl;
		std::cout << "Setting Out of bound Index" << std::endl;
		A.setIndex(100, 9999);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void test_overflow_pointer()
{
		Array<std::string> *A;
	try {
		A = new Array<std::string>(5);
		std::cout << (*A)[0] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete A;
}

void test_deep_copy() {
	std::cout << "--- Testing Deep Copy ---" << std::endl;

	Array<int> original(5);
	for (unsigned int i = 0; i < original.size(); i++) {
		original.setIndex(i, i * 10);
	}

	std::cout << "\nOriginal Array:" << std::endl;
	original.print();

	// Test the Copy Constructor
	Array<int> copy_constructed(original);
	std::cout << "Copied Array (via constructor):" << std::endl;
	copy_constructed.print();

	std::cout << "Modifying original[2] to 999..." << std::endl;
	original.setIndex(2, 999);

	std::cout << "\nOriginal Array after modification:" << std::endl;
	original.print();
	std::cout << "Copied Array should be UNCHANGED:" << std::endl;
	copy_constructed.print();

	std::cout <<  "\n--- Test the Assignment Operator ---" << std::endl;
	Array<int> copy_assigned;
	copy_assigned = original;
	std::cout << "Copied Array (via assignment operator):" << std::endl;
	copy_assigned.print();

	// 6. Modify the original again
	std::cout << "\nModifying original[0] to 111..." << std::endl;
	original.setIndex(0, 111);
	copy_assigned.setIndex(0, 8888);

	std::cout << "\nOriginal Array after second modification:" << std::endl;
	original.print();
	std::cout << "\nAssigned Array should be UNCHANGED:" << std::endl;
	copy_assigned.print();
}
