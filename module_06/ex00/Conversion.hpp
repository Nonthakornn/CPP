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
	// Need to make it static so that we dont need initiate class to call this function
	static void convert(const std::string &str);
};

# endif