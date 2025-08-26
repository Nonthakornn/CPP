#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("Default Presidential Form", 25, 5)
{
	// std::cout << "Default Presidential Constructor is called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm(target, 25, 5)
	,_target(target)
{
	// std::cout << "Parameter Presidential Constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
	:AForm(rhs)
{
	// std::cout << "Copy Presidential Constructor is called" << std::endl;
	*this = rhs;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	// std::cout << "Assignment Presidential Operator is called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "Presidential Form has been Destroy" << std::endl;
}
void PresidentialPardonForm::performAction() const {
	std::cout << this->getName() << "  has been pardoned by Zaphod Beeblebrox." << std::endl;
}
