#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("Default Robot Form", 72, 45)
{
	std::cout << "Default Robot Constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm(target, 145, 137)
	,_target(target)
{
	std::cout << "Parameter Robot Constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	:AForm(rhs)
{
	std::cout << "Copy Robot Constructor is called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) 
{
	std::cout << "Assignment Robot Operator is called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robot has been destroyed." << std::endl;
}

void RobotomyRequestForm::performAction() const {
	std::cout << "Bzzzzzz!" << std::endl;
	std::cout << this->getName() << " has been robotomized successfully 50% of the time." << std::endl;
}
