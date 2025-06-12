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
	Fixed(const Fixed& other);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	 toFloat(void) const;

	Fixed&	operator=(const Fixed &rhs);
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&		min(Fixed &class1, Fixed &class2);
	static Fixed&		max(Fixed &class1, Fixed &class2);
	static const Fixed&	min(const Fixed &class1, const Fixed &class2);
	static const Fixed&	max(const Fixed &class1, const Fixed &class2);
};

std::ostream& operator<<(std::ostream &out, Fixed const &fixed);

#endif