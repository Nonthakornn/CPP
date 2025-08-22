#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs):_name(rhs._name), _grade(rhs._grade) {
	std::cout << "Copy Constructor is called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Copy Assignment is called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade =  grade;
}

void Bureaucrat::increment() {
	setGrade(--this->_grade);
}

void Bureaucrat::decreament() {
	setGrade(++this->_grade);
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed" << form.getName();
	}
	catch(std::exception &e) {
		std::cout << this->getName () << " couldn't sign" << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low!");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
