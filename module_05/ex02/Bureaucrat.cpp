#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void):_name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name){
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat&copy) { *this = copy; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this == &rhs)
		return (*this);
	this->_grade = rhs.getGrade();
	return (*this);
}

void Bureaucrat::increment_grade() {
	this->setGrade(_grade - 1);
}

void Bureaucrat::decrement_grade() {
	this->setGrade(_grade + 1);
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low!");
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << " ,bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}