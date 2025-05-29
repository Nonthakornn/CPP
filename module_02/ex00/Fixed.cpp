#include "Fixed.hpp"

Fixed::Fixed()
	:m_fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &x)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = x;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed &rhs) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->m_fixed_point = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->m_fixed_point;
};

void Fixed::setRawBits(int const raw) {
	this->m_fixed_point = raw;
}
