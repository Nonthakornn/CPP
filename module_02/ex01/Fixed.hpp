#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int m_fixed_point;
	static const int m_fractional_bits = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed&	operator=(const Fixed &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	 toFloat(void) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const &fixed);

#endif