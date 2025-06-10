#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}

/*
a = Fixed(1234.4321f);
creates a temporary Fixed object using the float constructor
The copy assignment operator is called to assign this temporary object to a
After the assignment completes, the temporary object is no longer needed
The destructor is immediately called for this temporary object
*/

/*
If you want to convert back  /256 (divide)
Internal Storage
b.m_fixed_point = 2560   // represents 10.0  
c.m_fixed_point = 10860  // represents ~42.42
d.m_fixed_point = 2560   // represents 10.0 (copy of b)
*/
