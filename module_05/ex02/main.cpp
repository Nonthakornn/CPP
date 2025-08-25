#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void signed_execute_ShrubberyForm();
void signed_notExecute_ShrubberyForm();
void notSigned_notExecute_ShrubberyForm();
void test_robotomy();
void signed_execute_Presidential();
void notSigned_notExecute_Presidential();

int main()
{
	/* TESTING ShruberryForm */

	signed_execute_ShrubberyForm();
	signed_notExecute_ShrubberyForm();
	notSigned_notExecute_ShrubberyForm();

	/* TESTING RobotomyRequestForm*/
	test_robotomy();
	
	/* TESTING PresidentialPardonForm */
	signed_execute_Presidential();
	notSigned_notExecute_Presidential();

}

void signed_notExecute_ShrubberyForm() {
	//Require Grade sign 145, exec 137
	AForm *form = 0;
	try 
	{
		Bureaucrat b1("b1", 142);
		AForm *form = new ShrubberyCreationForm;

		std::cout << b1 << std::endl;
		std::cout << *form << std::endl;
		b1.signAForm(*form);
		b1.executeForm(*form);
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete form;
}

void signed_execute_ShrubberyForm() {
	AForm *form = 0;
	try 
	{
		Bureaucrat b1("b1", 100);
		AForm *form = new ShrubberyCreationForm;

		std::cout << b1 << std::endl;
		std::cout << *form << std::endl;
		b1.signAForm(*form);
		b1.executeForm(*form);
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete form;
}

void notSigned_notExecute_ShrubberyForm() {
	AForm *form = 0;
	try 
	{
		Bureaucrat b1("b1", 150);
		AForm *form = new ShrubberyCreationForm;
		std::cout << b1 << std::endl;
		std::cout << *form << std::endl;
		b1.signAForm(*form);
		b1.executeForm(*form);
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete form;
}


void test_robotomy() {
	try {
		srand(time(0));
		Bureaucrat b("Mr Robot", 40);
		RobotomyRequestForm robotForm("Bender");

		std::cout << b << std::endl;
		std::cout << robotForm << std::endl;
		b.signAForm(robotForm);
		b.executeForm(robotForm);
		b.executeForm(robotForm);
		b.executeForm(robotForm);
	}
	catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void signed_execute_Presidential() {
	try {
		Bureaucrat b3("b3", 3);
		PresidentialPardonForm p("p-form");
		b3.signAForm(p);
		b3.executeForm(p);
	}
	catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}


void notSigned_notExecute_Presidential() {
	try {
		Bureaucrat b3("b3", 123);
		PresidentialPardonForm p("p-form");
		b3.signAForm(p);
		b3.executeForm(p);
	}
	catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}