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
	const int			_signGrade;
	const int			_executeGrade;
public:
	Form(void);
	Form(const std::string name, const int gradeSign, const int gradeExecute);
	Form(const Form &cpy);
	Form& operator=(const Form &rhs);
	~Form();

	std::string	getName() const;
	bool		getSignStatus() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;

	void		beSigned(Bureaucrat &bureaucrat);
	void		signedForm();

	class GradeTooHighException: public std::exception {
	public:
	 virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
	 virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, Form const &form);

# endif