#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <iomanip>      // std::fixed and std::setprecision
# include <limits>       // numeric_limits
# include <cctype>       // isprint, isdigit
# include <cstdlib>      // strtod

class ScalarConverter {
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& rhs);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter(void);

public:
	static void convert(const std::string &str);
};

# endif