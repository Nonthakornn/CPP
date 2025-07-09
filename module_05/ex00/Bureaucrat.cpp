#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat has constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat&copy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat has destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	std::cout << "Bureaucrat copy operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	return out;
}