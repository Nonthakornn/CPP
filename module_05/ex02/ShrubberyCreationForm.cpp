#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Default Shrubbery Form", 145, 137)
{
	std::cout << "Default Shrubbery Constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137)
	, _target(target)
{
	std::cout << "Parameter Shrubbery Constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	:AForm(rhs)
{
	std::cout << "Copy Shrubbery Constructor is called" << std::endl;
	*this = rhs;
}

void ShrubberyCreationForm::performAction() const {
	//TODO Make ASCII Later
	std::cout << "ASCIIIIIIIIIII TREEEEE!!!!!" << std::endl;

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << "Assignment Shrubbery is called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery has beed destroyed" << std::endl;
}
