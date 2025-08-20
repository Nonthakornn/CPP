#include "AForm.hpp"

Form::Form(void)
	:_name("Default_Form")
	,_isSigned(false)
	,_signGrade(150)
	,_executeGrade(150)
{}


Form::Form(const std::string name, const int signGrade, const int executeGrade)
	:_name(name)
	,_isSigned(false)
	,_signGrade(signGrade)
	,_executeGrade(executeGrade)
{}

Form::Form(const Form &cpy)
	:_name(cpy._name)
	,_isSigned(cpy._isSigned)
	,_signGrade(cpy._signGrade)
	,_executeGrade(cpy._executeGrade)
{}

Form& Form::operator=(const Form &rhs) {
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const { return this->_name; }
bool Form::getSignStatus() const { return this->_isSigned; }
int Form::getGradeSign() const { return this->_signGrade; }
int Form::getGradeExecute() const {return this->_executeGrade; }

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}


std::ostream& operator<<(std::ostream &out, Form const &form) {
	out <<
	"Name: " << form.getName() << "\n" << 
	"Sign Status: " << form.getSignStatus()  << "\n" <<
	"Sign Grade: " << form.getGradeSign() << "\n" <<
	"Execute Grade: " << form.getGradeExecute();
	return (out);
}