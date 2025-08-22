#include "Form.hpp"
#include "Bureaucrat.hpp"

void test_default_form();
void test_copy_assignment();
void test_grade_too_low_high();
void test_pass_form();
void test_fail_form();
void test_bureaucrat_pass();
void test_bureaucrat_fail();

int main() {
	test_default_form();
	test_grade_too_low_high();
	test_pass_form();
	test_fail_form();
	test_bureaucrat_pass();
	test_bureaucrat_fail();
}

void test_default_form() {
	std::cout << "Default Constructor" << std::endl;
	Form f;
	std::cout << f << std::endl;

	std::cout << "Parameter Constructor" << std::endl;
	Form f1("form-1", 120, 130);
	std::cout << f1 << std::endl;

	std::cout << "Copy Constructor" << std::endl;
	Form f2 = f1;
	std::cout << f2 << std::endl;
}

void test_grade_too_low_high() {
	{
		try {
			Form f("form-too-low", 151);
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Form f("form-too-high", 0);
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Form f("form-too-low", 151, -1);
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void test_pass_form() {
	Bureaucrat b1("b1",50);
	std::cout << b1 << std::endl;
	Form f("Form-pass", 120);
	f.beSigned(b1);
	std::cout << f << std::endl;
}

void test_fail_form() {
	try {
		Bureaucrat b1("b1",121);
		std::cout << b1 << std::endl;
		Form f("Form-fail", 120);
		std::cout << f << std::endl;
		f.beSigned(b1);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void test_bureaucrat_pass() {

	try {
		Bureaucrat  bPass("bpass", 12);
		Form f("Pass form", 130);
		bPass.signForm(f);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void test_bureaucrat_fail() {
	try {
		Bureaucrat  bPass("bfail", 12);
		Form f("Fail form", 1);
		bPass.signForm(f);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}