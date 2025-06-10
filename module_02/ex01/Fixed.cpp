#include "Fixed.hpp"

/*
If you want to stored x256 (multiply)
If you want to convert back  /256 (divide)

Summarize:
1. Stored the value internal storage first (INT or FLOAT) - storage number
	- INT - num << 8 (num * 256)
	- FLOAT - round(num * (1 << 8))  similar to round(num * 256)
		[Integer Part] [8-bit Fractional Part]
		24 bits         8 bits
2. Convert back to type that we want
	- INT - storage number (num * 256) >> 8
	- FLOAT - storage number / (1 << 8) 
*/

Fixed::Fixed()
	:m_fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
This is an Internal storage of computer
Fixed const b(10):
10 in binary:     00000000 00000000 00000000 00001010
10 << 8:          00000000 00000000 00001010 00000000  (= 2560)
                                   integer   fractional
                                   part=10   part=0
*/
Fixed::Fixed(const int num)
	:m_fixed_point(num << m_fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

/*
[Integer Part] [8-bit Fractional Part]
   24 bits         8 bits
example:
3.5

Step 1: shift bit
1 << 8
shift 0: 00000000 00000000 00000000 00000001  (= 1)
shift 1: 00000000 00000000 00000000 00000010  (= 2)
shift 2: 00000000 00000000 00000000 00000100  (= 4)
shift 3: 00000000 00000000 00000000 00001000  (= 8)
shift 4: 00000000 00000000 00000000 00010000  (= 16)
shift 5: 00000000 00000000 00000000 00100000  (= 32)
shift 6: 00000000 00000000 00000000 01000000  (= 64)
shift 7: 00000000 00000000 00000000 10000000  (= 128)
shift 8: 00000000 00000000 00000001 00000000  (= 256)

Step2: Multiply num * shift bit
round(3.5 x 256 = 896)

Step3: Vusulize binary
896 in binary: 00000000 00000000 00000011 10000000
                              	 integer  fractional

Verify:
	Integet part: 3
	Fractional part: 128/256 = 0.5
	Total = 3.5
*/

Fixed::Fixed(const float num)
	:m_fixed_point(round(num * (1 << m_fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	// this->m_fixed_point = other.m_fixed_point;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->m_fixed_point = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->m_fixed_point);
}

void Fixed::setRawBits(int const raw) {
	this->m_fixed_point = raw;
}

/*
Fixed const b(10);
After Constructor it keep the value internal
b.m_fixed_point = 2560  // This is what's actually stored
b.m_fractional_bits = 8 
return ((float)this->m_fixed_point / (float)(1 << this->m_fractional_bits));
       ((float)2560           / (float)256);
*/
float Fixed::toFloat(void) const {
	//Convert back  Internal storage/256 
	return ((float)this->m_fixed_point / (float)(1 << this->m_fractional_bits));
}

/*

Fixed const c(42.42f);
c.m_fixed_point = 10860 (42.42 * 256)
c.m_fractional_bits = 8

10860 >> 8
10860 in binary: 00000000 00000000 00101010 01101100
                                  integer   fractional
                                  part=42   part=108

Before >> 8:  [  42  ][  108  ]  42 integer part, 108 fractional part
              Keep    Discard

After >> 8:   [   0  ][  42  ] Result is 42

*/
int Fixed::toInt(void) const {
	return (this->m_fixed_point >> this->m_fractional_bits);
}

std::ostream& operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}
