#include "Bureaucrat.hpp"

void test_parameter_constructor();
void test_grade_too_low();
void test_grade_too_high();
void test_decrease();
void test_increase();

int main() {
	test_parameter_constructor();
	test_grade_too_low();
	test_grade_too_high();
	test_decrease();
	test_increase();
	return (0);
}

void test_increase() {

	Bureaucrat t0("t0", 5);
	std::cout << "Before Decrease: " << t0 << std::endl;

	try
	{
		for (int i = 0; i < 5; i++)
			t0.increment_grade();
		std::cout << "After Decrease: " << t0 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error cannot increment from grade: " << t0.getGrade() << " - " << e.what() << std::endl;
	}

}

void test_decrease()
{
	Bureaucrat t1;
	std::cout << "Before Decrease: " << t1 << std::endl;

	try
	{
		t1.decrement_grade();
		std::cout << "After Decrease: " << t1 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error cannot decrement from grade: " << t1.getGrade() << " - " << e.what() << std::endl;
	}
}

void test_grade_too_low()
{
	Bureaucrat *p1 = NULL;

	try
	{
		p1 = new Bureaucrat("p1", 1200);
		std::cout << *p1 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		/* e is just a variable that holds the exception object that was thrown */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (p1)
		delete p1;
}

void test_grade_too_high()
{
	try {
		Bureaucrat p2("p2", -1);
		std::cout << p2 << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void test_parameter_constructor()
{
	try {
		Bureaucrat p0("p0", -1);
		// Bureaucrat p1("p0", 190);
		std::cout << p0 << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

}