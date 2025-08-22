#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;	
	const int			_grade_to_sign;
	const int			_grade_to_execute;

public:

	Form();
	Form(const std::string name, const int grade_to_sign);
	Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();

	std::string getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;
	void		beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

# endif