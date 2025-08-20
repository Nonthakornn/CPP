#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;
public:
	AForm(void);
	AForm(const std::string name, const int gradeSign, const int gradeExecute);
	AForm(const AForm &cpy);
	AForm& operator=(const AForm &rhs);
	~AForm();

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

std::ostream& operator<<(std::ostream &out, AForm const &form);

# endif