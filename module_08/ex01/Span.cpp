#include "Span.hpp"

Span::Span():_N(0)
{
	// std::cout << "Default Constructor is called" << std::endl;
};

Span::Span(unsigned int N)
	:_N(N)
{
	// std::cout << "Parameter Constructor is called" << std::endl;
};

Span::Span(const Span& rhs)
	:_N(rhs._N)
	,_vec(rhs._vec)
{
	// std::cout << "Copy Constructor is called" << std::endl;
};


Span& Span::operator=(const Span& rhs) {
	// std::cout << "Copy Assignment is called" << std::endl;
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_vec = rhs._vec;
	}
	return (*this);
};

Span::~Span() {
	// std::cout << "Destructor is called" << std::endl;
};

void Span::addNumber(int num)
{
	if (this->_vec.size() >= _N)
		throw std::length_error("Container is already full!");
	this->_vec.push_back(num);
}

void Span::displayVector()
{
	for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int Span::shortestSpan() {
	int diff = 0;
	int l = 0;
	int result = INT_MAX;
	std::vector<int> vec = this->_vec;

	std::sort(vec.begin(), vec.end());
	for (size_t r = 1; r < vec.size(); r++)
	{
		diff = vec[r] - vec[l];
		result = std::min(result, diff);
		l++;
	}
	return (result);
}
