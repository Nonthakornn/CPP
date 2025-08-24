#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
class RobotomyRequestForm: public AForm {
private:
	std::string _target;
public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	void performAction() const;
	


};



#endif