#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog& 		operator=(const Dog& rhs);
	std::string	getType() const;
	void		makeSound() const;
};

#endif