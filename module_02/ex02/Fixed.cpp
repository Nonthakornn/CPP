#include "Fixed.hpp"

/* Constructor & Destrucor*/
Fixed::Fixed():m_fixed_point(0) {}

Fixed::Fixed(const int num):m_fixed_point(num << this->m_fractional_bits) {}

Fixed::Fixed(const float num):m_fixed_point(round(num * (1 << this->m_fractional_bits))) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::~Fixed() {}

/* Arithmetic Operator */
Fixed& Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs)
		this->m_fixed_point = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed temp;
	
	temp = this->toFloat() + rhs.toFloat();
	return (temp);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed temp;

	temp = this->toFloat() * rhs.toFloat();
	return (temp);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/* Comparison */
bool	Fixed::operator>(const Fixed &rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const {
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const {
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const {
	return (this->getRawBits() != rhs.getRawBits());
}

/* Pre-Post Increment */

/*
Fixed	Fixed::operator++(void) {

Memory Address: 0x1000          Memory Address: 0x2000 (return value)
Object 'a': [m_fixed_point: 1279]    Copy of 'a': [m_fixed_point: 1279]
            represents 4.99609375                represents 4.99609375

std::cout << --a << std::endl;  // Prints: 4.99609375 (the NEW value)
std::cout << a << std::endl;    // Prints: 4.99609375 (same value)
Creates a TEMP copy and returns it (Which cannot make chain)
*/

Fixed&	Fixed::operator++(void) {
	/* ++m_fixed_point → adds the smallest possible value (1 / 256) */
	++(this->m_fixed_point); //(0 + 1)
	// In real life ++ is +=1 can do it this way
	// this->m_fixed_point += (1 << this->m_fractional_bits); //(0 + 256)
	return (*this);
}

/*
The int in operator++(int) is just a dummy parameter that C++ uses to tell the difference between ++a and a++.
You never actually pass a value to it - C++ handles this automatically.
*/

Fixed	Fixed::operator++(int) {
	Fixed temp;

	temp = *this;
	(this->m_fixed_point)++;
	return (temp);
}

Fixed& Fixed::operator--(void) {
	--(this->m_fixed_point);
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp;
	temp = *this;
	(this->m_fixed_point)--;
	return (temp);
}

Fixed& Fixed::min(Fixed& class1, Fixed& class2) {
	return (class1 < class2 ? class1 : class2);
}

Fixed& Fixed::max(Fixed& class1, Fixed& class2) {
	return (class1 > class2 ? class1 : class2);
}

const Fixed& Fixed::min(const Fixed& class1, const Fixed& class2) {
	return (class1 < class2 ? class1 : class2);
}

const Fixed& Fixed::max(const Fixed& class1, const Fixed& class2) {
	return (class1 > class2 ? class1 : class2);
}

/* Functions */
int Fixed::getRawBits(void) const { return (this->m_fixed_point); }

void Fixed::setRawBits(int const raw) { this->m_fixed_point = raw; }

int Fixed::toInt(void) const {
	return (this->m_fixed_point >> this->m_fractional_bits);
}

float Fixed::toFloat(void) const {
	/* smallest representable =  1 / 256 = 0.00390625 */
	// std::cout << (float)this->m_fixed_point <<  "/" <<  (float)(1 << this->m_fractional_bits) << std::endl;
	return ((float)this->m_fixed_point / (float)(1 << this->m_fractional_bits));
}

/* Ostream */
std::ostream & operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}
