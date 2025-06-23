#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
public:
	std::string idea[100];
	Brain();
	Brain(const Brain& copy);
	~Brain();
	Brain& operator=(const Brain &rhs);
};


#endif