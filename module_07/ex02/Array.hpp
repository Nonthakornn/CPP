#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <typeinfo>
#include <exception>
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
		:a(new T[rhs._size]) 
		,_size(rhs._size)
	{
		// Direct Implementation (I used this implementation)
		// Delegating Implementation
		std::cout << "Copy Constructor called" << std::endl;
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

	T& operator[] (unsigned int index)
	{
		if (index >= this->size() || !(this->a))
			throw InvalidException();
		return (a[index]);
	}

	void setIndex(unsigned int index, T data)
	{
		if (index >= this->size() || !(this->a))
			throw InvalidException();
		this->a[index] = data;
	}

	void print() {
		for (unsigned int i = 0; i < this->size(); i++)
			std::cout << this->a[i] << std::endl;
	}

	~Array() {
		if (a != NULL)
			delete[] a;
	}

	unsigned int size() const {
		return (this->_size); 
	};

	class InvalidException: public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Index out of bounds");
		}
	};
};

# endif