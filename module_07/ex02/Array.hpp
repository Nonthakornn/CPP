#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <typeinfo>

template<typename T>

class Array {
private:
	T *a;
	unsigned int _size;

public:
	Array():_size(0) {
		std::cout << "Default Constructor is called" << std::endl;
		a = new T[_size];
	}

	Array(unsigned int n):_size(n) {
		std::cout << "Parameter Constructor is called" << std::endl;
		a = new T[_size]();
		// for (unsigned int i = 0; i < n; i++)
		// 	std::cout << *(a+i) << std::endl;
	}
	
	Array(const Array& rhs)
	:_size(rhs._size)
	{
		// Direct Implementation (I used this implementation)
		// Delegating Implementation
		std::cout << "Copy Constructor called." << std::endl;
		a = new T[_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->a[i] = rhs.a[i];
	}

	Array& operator=(const Array& rhs) {
		std::cout << "Assignment operator called." << std::endl;
		if (this != &rhs)
		{
			//Delete old memory if it is not self-assignment.
			delete[] a;
			this->_size = rhs._size;
			this->a = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->a[i] = rhs.a[i];
		}
		return (*this);
	}

	~Array() {
		if (a != NULL)
			delete[] a;
	}

	int size() const { return (this->_size); };
};

# endif