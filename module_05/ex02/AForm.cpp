#include "AForm.hpp"

AForm::AForm()
:_name("Default AForm")
,_isSigned(false)
, _grade_to_sign(150)
, _grade_to_execute(150)
{
	std::cout << "AForm Constructor is called" << std::endl;
}

AForm::AForm(const std::string name, const int grade_to_sign)
:_name(name)
,_isSigned(false)
,_grade_to_sign(grade_to_sign)
,_grade_to_execute(150)
{
	std::cout << "AForm Parameter Constructor is called" << std::endl;
	if (grade_to_sign > 150)
		throw GradeTooLowException();
	else if (grade_to_sign < 1)
		throw GradeTooHighException();
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute)
:_name(name)
,_isSigned(false)
,_grade_to_sign(grade_to_sign)
,_grade_to_execute(grade_to_execute)
{
	std::cout << "AForm Parameter Constructor is called" << std::endl;
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& rhs)
:_name(rhs._name)
,_isSigned(rhs._isSigned)
,_grade_to_sign(rhs._grade_to_sign)
,_grade_to_execute(rhs._grade_to_execute)
{ std::cout << "Copy Constructor is called" << std::endl; }

AForm& AForm::operator=(const AForm& rhs) {
	std::cout << "Copy Assigment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm has beed destroyed" << std::endl;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getSignGrade() const {
	return this->_grade_to_sign;
}

int AForm::getExecuteGrade() const {
	return this->_grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() < this->getSignGrade())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm Grade Too Low");
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm) {
	out << "Name: " << AForm.getName() << "\n"
	<< "Is Signed: " << AForm.getIsSigned() << "\n"
	<< "Grade to Signed: " << AForm.getSignGrade() << "\n"
	<< "Grade to Execute: " << AForm.getExecuteGrade();
	return (out);
}