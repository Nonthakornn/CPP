#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
private:

protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal& 				operator=(const Animal &rhs);
	virtual std::string		getType() const;
	virtual void			makeSound() const = 0;
};

#endif