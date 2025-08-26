#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("Default Robot Form", 72, 45)
{
	// std::cout << "Default Robot Constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm(target, 72, 45)
	,_target(target)
{
	// std::cout << "Parameter Robot Constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	:AForm(rhs)
{
	// std::cout << "Copy Robot Constructor is called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) 
{
	// std::cout << "Assignment Robot Operator is called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Robot has been destroyed." << std::endl;
}

void RobotomyRequestForm::performAction() const {
	std::cout << "Bzzzzzz!" << std::endl;
	if (rand() % 2 == 0) { // rand() % 2 will be 0 or 1
		std::cout << this->getName() << " has been robotomized successfully." << std::endl;
	} else {
		throw RobotomyFailException();
	}
}

const char* RobotomyRequestForm::RobotomyFailException::what() const throw() {
	return ("Robotomy failed");
}
