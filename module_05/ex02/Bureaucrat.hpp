#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& rhs);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

	std::string	getName() const;
	int			getGrade() const;
	void		setGrade(int grade);
	void		increment();
	void		decreament();
	void		signAForm(AForm &AForm);
	void		executeForm(AForm const &form);

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif