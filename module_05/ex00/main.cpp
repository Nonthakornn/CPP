#include "Bureaucrat.hpp"

void test_parameter_and_copy_constructor();
void test_grade_too_low();
void test_grade_too_high();
void test_decrease_fail();
void test_decrease_success();
void test_increase_fail();
void test_increase_success();

int main() {
	test_parameter_and_copy_constructor();
	test_grade_too_low();
	test_grade_too_high();
	test_decrease_fail();
	test_decrease_success();
	test_increase_fail();
	test_increase_success();
	return (0);
}

void test_parameter_and_copy_constructor() {
	Bureaucrat b0;
	std::cout << b0 << std::endl;

	Bureaucrat b1("b1", 120);
	Bureaucrat b2(b1);
	std::cout << b2 << std::endl;
}

void test_grade_too_low() {
	try {
		Bureaucrat b3("b3", 153);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

void test_grade_too_high() {
	try {
		Bureaucrat b4("b4", 0);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}


void test_decrease_fail() {
	try {
		Bureaucrat b5("b5", 150);
		b5.decreament();
		//Should not print anything
		std::cout << b5 << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}


void test_decrease_success() {
	try {
		Bureaucrat b6("b6", 149);
		b6.decreament();
		std::cout << b6 << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

void test_increase_fail() {
	try {
		Bureaucrat b7("b7", 1);
		b7.increment();
		std::cout << b7 << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

void test_increase_success() {
	try {
		Bureaucrat b8("b8", 12);
		b8.increment();
		std::cout << b8 << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}