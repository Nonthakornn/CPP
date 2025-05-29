#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int m_fixed_point;
	static const int m_fractional_bits = 8;
public:
	Fixed();
	Fixed(Fixed &x);
	~Fixed();
	Fixed&	operator=(Fixed &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif