#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include <exception>

class AForm;

class Intern {
private:
public:
	Intern(void);
	Intern(const Intern &rhs);
	~Intern();
	Intern& operator=(const Intern& rhs);

	AForm* makeForm(const std::string form_name, const std::string target_form);

	class ErrorFormException: public std::exception {
	public:
		virtual const char * what() const throw();
	};

};


# endif