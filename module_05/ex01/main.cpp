#include "Form.hpp"
#include "Bureaucrat.hpp"

void test_grade_too_low();
void test_grade_too_high();
void test_not_pass_form();
void test_pass_form();

int main() {
	test_grade_too_low();
	test_grade_too_high();
	test_not_pass_form();
	test_pass_form();
}


void test_grade_too_low() {
	try {
		Bureaucrat p1("p1", 5520);
		Form form1("form1", 100, 100);
	}	
	catch (const std::exception &e){
		std::cout << "Exception Founded: " << e.what() << std::endl;
	}
}

void test_grade_too_high() {
	try {
		Bureaucrat p1("p2", -1);
		Form form1("form1", 100, 100);
		p1.signForm(form1);
	}	
	catch (const std::exception &e){
		std::cout << "Exception Founded: " << e.what() << std::endl;
	}
}

void test_not_pass_form() {
	try {
		Bureaucrat p1("p3", 120);
		Form form("form1", 100, 100);
		p1.signForm(form);
	}	
	catch (const std::exception &e){
		std::cout << "Exception Founded: " << e.what() << std::endl;
	}
}

void test_pass_form() {
	try {
		Bureaucrat p1("p4", -12);
		Form form("form1", 100, 100);
		p1.signForm(form);
	}	
	catch (const std::exception &e){
		std::cout << "Exception Founded: " << e.what() << std::endl;
	}
}