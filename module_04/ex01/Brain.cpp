#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Class is constructed" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea[i]  = "I hate this project";
		// std::cout <<"[" << i+1 << "] " << idea[i] << std::endl;
	}
	idea[42] = "I Love this project";
}

Brain::Brain(const Brain& copy) {
	*this = copy;
}

Brain& Brain::operator=(const Brain &rhs) {
	for (int i = 0; i < 100; i++)
		this->idea[i] = rhs.idea[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain is deconstructed" << std::endl;
}