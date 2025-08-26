#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void sign_presidentail_form();
void sign_shrubbery_form();
void sign_robotomy_form();
void error_createform();

int main()
{
	sign_presidentail_form();
	sign_shrubbery_form();
	sign_robotomy_form();
	error_createform();
}
void sign_presidentail_form() {
	Bureaucrat bob("Bob",2);
	Intern someRandomIntern;
	AForm* rrf = 0;
	try {
		rrf = someRandomIntern.makeForm("Presidential request", "Presidential Form");
		bob.signAForm(*rrf);
	}	
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
}

void sign_shrubbery_form() {
	Bureaucrat mike("Mike",2);
	Intern someRandomIntern;
	AForm* rrf = 0;
	try {
		rrf = someRandomIntern.makeForm("Shrubberry request", "Shrubberry Form");
		mike.signAForm(*rrf);
		mike.executeForm(*rrf);
	}	
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;

}

void sign_robotomy_form() {
	Bureaucrat john("John",2);
	Intern someRandomIntern;
	AForm* rrf = 0;
	srand(time(0));
	try {
		rrf = someRandomIntern.makeForm("Robotomy request", "Robotomy Form");
		john.signAForm(*rrf);
		john.executeForm(*rrf);
	}	
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
}
void error_createform() {
	Bureaucrat jack("Jack",2);
	Intern someRandomIntern;
	AForm* rrf = 0;
	srand(time(0));
	try {
		rrf = someRandomIntern.makeForm("Shubb request", "??? Form");
		jack.signAForm(*rrf);
		jack.executeForm(*rrf);
	}	
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
}