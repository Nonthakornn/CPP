#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <time.h>
# include <cstdlib>
# include <ctime>
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

	class RobotomyFailException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif