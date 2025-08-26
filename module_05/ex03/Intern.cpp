#include "Intern.hpp"

Intern::Intern(void) {};

Intern::Intern(const Intern &rhs){
	(void)rhs;
}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return (*this);
}

Intern::~Intern(void) {};

AForm* Intern::makeForm(const std::string form_name, const std::string target_form) {

	int i = 0;
	std::string form_list[] = {"Presidential request", "Robotomy request", "Shrubberry request"};
	int list_size =  sizeof(form_list) / sizeof(form_list[0]);

	while (i < list_size && (form_list[i].compare(form_name)))
		i++;

	switch (i) {
		case 0:
			std::cout << "Intern creates " << target_form << std::endl;
			return (new PresidentialPardonForm(target_form));
		case 1:
			std::cout << "Intern creates " << target_form << std::endl;
			return(new RobotomyRequestForm(target_form));
		case 2:
			std::cout << "Intern creates " << target_form << std::endl;
			return (new ShrubberyCreationForm(target_form));
		default:
			throw ErrorFormException();
	}
}

const char * Intern::ErrorFormException::what() const throw() {
	return ("Error: There is no form");
}