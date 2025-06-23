#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *dog_brain;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog& 		operator=(const Dog& rhs);
	std::string	getType() const;
	void		makeSound() const;
	std::string	getIdea(int num);
	void 		setIdea(int num, std::string new_idea);
};

#endif