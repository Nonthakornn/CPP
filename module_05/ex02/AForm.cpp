#include "AForm.hpp"

AForm::AForm(void)
	:_name("Default_Form")
	,_isSigned(false)
	,_signGrade(150)
	,_executeGrade(150)
{}


AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
	:_name(name)
	,_isSigned(false)
	,_signGrade(signGrade)
	,_executeGrade(executeGrade)
{}

AForm::AForm(const AForm &cpy)
	:_name(cpy._name)
	,_isSigned(cpy._isSigned)
	,_signGrade(cpy._signGrade)
	,_executeGrade(cpy._executeGrade)
{}

AForm& AForm::operator=(const AForm &rhs) {
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const { return this->_name; }
bool AForm::getSignStatus() const { return this->_isSigned; }
int AForm::getGradeSign() const { return this->_signGrade; }
int AForm::getGradeExecute() const {return this->_executeGrade; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char * AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}


std::ostream& operator<<(std::ostream &out, AForm const &form) {
	out <<
	"Name: " << form.getName() << "\n" << 
	"Sign Status: " << form.getSignStatus()  << "\n" <<
	"Sign Grade: " << form.getGradeSign() << "\n" <<
	"Execute Grade: " << form.getGradeExecute();
	return (out);
}