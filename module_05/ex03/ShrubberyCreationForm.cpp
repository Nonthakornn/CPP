#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Default_Shrubbery", 145, 137)
	,_target("Default_Shrubberry")
{
	// std::cout << "Default Shrubbery Constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137)
	, _target(target)
{
	// std::cout << "Parameter Shrubbery Constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	:AForm(rhs)
{
	// std::cout << "Copy Shrubbery Constructor is called" << std::endl;
	*this = rhs;
}

void ShrubberyCreationForm::performAction() const {
	// <target>_shrubbery
	std::ofstream outf((this->_target + "_shrubberry.txt").c_str());
	if (!(outf.is_open()))
	{
		throw ErrorfileExcepion();
	}
	outf
		<< "      /\\\n"
		<< "     /  \\\n"
		<< "    /    \\\n"
		<< "   /      \\\n"
		<< "  /________\\\n"
		<< "     ||||\n"
		<< "     ||||\n";
	outf.close();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	// std::cout << "Assignment Shrubbery is called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "Shrubbery has beed destroyed" << std::endl;
}

const char* ShrubberyCreationForm::ErrorfileExcepion::what() const throw() {
	return ("Error Opening file");
}
