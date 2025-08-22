#include "Form.hpp"

Form::Form()
:_name("Default Form")
,_isSigned(false)
, _grade_to_sign(150)
, _grade_to_execute(150)
{}

Form::Form(const std::string name, const int grade_to_sign)
:_name(name)
,_isSigned(false)
,_grade_to_sign(grade_to_sign)
,_grade_to_execute(150)
{
	if (grade_to_sign > 150)
		throw GradeTooLowException();
	else if (grade_to_sign < 1)
		throw GradeTooHighException();
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute)
:_name(name)
,_isSigned(false)
,_grade_to_sign(grade_to_sign)
,_grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& rhs)
:_name(rhs._name)
,_isSigned(rhs._isSigned)
,_grade_to_sign(rhs._grade_to_sign)
,_grade_to_execute(rhs._grade_to_execute)
{ std::cout << "Copy Constructor is called" << std::endl; }

Form& Form::operator=(const Form& rhs) {
	std::cout << "Copy Assigment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getSignGrade() const {
	return this->_grade_to_sign;

}
int Form::getExecuteGrade() const {
	return this->_grade_to_execute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() < this->getSignGrade())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form Grade Too Low");
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Name: " << form.getName() << "\n"
	<< "Is Signed: " << form.getIsSigned() << "\n"
	<< "Grade to Signed: " << form.getSignGrade() << "\n"
	<< "Grade to Execute: " << form.getExecuteGrade();
	return (out);
}