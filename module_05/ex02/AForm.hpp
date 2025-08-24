#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;	
	const int			_grade_to_sign;
	const int			_grade_to_execute;

public:

	AForm();
	AForm(const std::string name, const int grade_to_sign);
	AForm(const std::string name, const int grade_to_sign, const int grade_to_execute);
	AForm(const AForm& rhs);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	std::string getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;
	void		beSigned(const Bureaucrat &bureaucrat);

	virtual void		performAction() const = 0;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

# endif