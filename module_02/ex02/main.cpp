#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

/*
int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 10) + Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const e( Fixed( 4.0f ) / Fixed( 2 ) );

	std::cout << "Arithmetic:" << std::endl;
	std::cout << "Default: " << a << std::endl;
	std::cout << "Arimetic *: " << b << std::endl;
	std::cout << "Arimetic +: " << c << std::endl;
	std::cout << "Arimetic -: " << d << std::endl;
	std::cout << "Arimetic /: " << e << std::endl;

	std::cout<< "___________________" << std::endl;

	std::cout << "\nComparison:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "(a > b): " << ((a > b) ? "True" : "False") << std::endl;
	std::cout << "(a < b): " << ((a < b) ? "True" : "False") << std::endl;
	std::cout << "(a >= b): " << ((a >= b) ? "True" : "False") << std::endl;
	std::cout << "(a <= b): " << ((a <= b) ? "True" : "False") << std::endl;
	std::cout << "(a == b): " << ((a == b) ? "True" : "False") << std::endl;
	std::cout << "(a != b): " << ((a != b) ? "True" : "False") << std::endl;

	std::cout<< "___________________" << std::endl;

	Fixed f(0);
	std::cout << "\nPre Increment:" << std::endl;
	// std::cout << "++a: " << ++(++a) << std::endl;
	std::cout << "f before pre-increment: " << f << std::endl;
	std::cout << "++f: " << (++f) << std::endl;
	std::cout << "f after pre-increment: " << f << std::endl;

	std::cout<< "___________________" << std::endl;
	Fixed g(0);
	std::cout << "\nPost Increment:" << std::endl;
	std::cout << "g before post-increment: " << g << std::endl;
	std::cout << "g++: " << g++ << std::endl;
	std::cout << "g after post-increment: " << g << std::endl;

	std::cout<< "___________________" << std::endl;
	Fixed h(1);
	std::cout << "\nPre Increment:" << std::endl;
	std::cout << "h before pre-increment: " << h << std::endl;
	std::cout << "--h: " << (--h) << std::endl;
	std::cout << "h after pre-increment: " << h << std::endl;

	std::cout<< "___________________" << std::endl;
	Fixed i(1);
	std::cout << "\nPost Increment:" << std::endl;
	std::cout << "i before post-increment: " << i << std::endl;
	std::cout << "i++: " << i-- << std::endl;
	std::cout << "i after post-increment: " << i << std::endl;

	std::cout<< "___________________" << std::endl;
	std::cout << "\nMin Max" << std::endl;
	Fixed j(5);
	Fixed k(6);
	std::cout << "j: "<< j << " k: " << k << std::endl;
	std::cout << "min(j,k): " << Fixed::min(j,k) << std::endl;
	std::cout << "max(j,k): " << Fixed::max(j,k) << std::endl;

	std::cout<< "___________________" << std::endl;
	std::cout << "\nConst Min Max" << std::endl;
	const Fixed l(5);
	const Fixed m(6);
	std::cout << "j: "<< l << " k: " << m << std::endl;
	std::cout << "min(j,k): " << Fixed::min(l,m) << std::endl;
	std::cout << "max(j,k): " << Fixed::max(l,m) << std::endl;

	return 0;
}
*/