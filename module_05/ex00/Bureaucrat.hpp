#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
private:
	std::string name;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat &rhs);

	void GradeTooHighException();
	void GradeTooLowException();

	std::string getName() const;
	int getGrade() const;
	void increment_grade();
	void decrement_grade();

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif