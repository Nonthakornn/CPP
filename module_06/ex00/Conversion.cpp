#include "Conversion.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs) { *this = rhs;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return (*this);
};

ScalarConverter::~ScalarConverter() {}

//Check not a Number
static bool isNan98(double d)
{
	return (d != d);
}

static bool isInf98(double d)
{
	return (d == std::numeric_limits<double>::infinity()
		|| d == -std::numeric_limits<double>::infinity());
}

static std::string ltrim(const std::string& s) {
	size_t start = s.find_first_not_of(" \t\n\r\f\v");
	return (start == std::string::npos) ? "" : s.substr(start);
}

static std::string rtrim(const std::string& s) {
	size_t end = s.find_last_not_of(" \t\n\r\f\v");
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

static std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}

static void printChar(double d) {
	std::cout << "char: ";
	if (isNan98(d) || isInf98(d) || d < 0 || d > 127) {
		std::cout << "impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(d);
	if (!std::isprint(c)) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << c << "'" << std::endl;
	}
}

static void printInt(double d) {
	std::cout << "int: ";

	if (isNan98(d) || isInf98(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(d) << std::endl;
	}
}
static void printFloat(double d) {
	std::cout << "float: " << static_cast<float>(d);
	// Add ".0" for whole numbers to match the required output
	if (!isNan98(d) && !isInf98(d) && d == static_cast<int>(d)) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

static void printDouble(double d) {
    std::cout << "double: " << d;
    // Add ".0" for whole numbers
    if (!isNan98(d) && !isInf98(d) && d == static_cast<int>(d)) {
        std::cout << ".0";
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	std::string trimed_str = trim(str);

	// Handle empty string
	if (trimed_str.empty())
	{
		std::cerr << "Error: String Emmpty" << std::endl;
		return ;
	}
	// Handle single character non-digit literal
	if (trimed_str.length() == 1 && !isdigit(trimed_str[0]))
	{
		std::cout << trimed_str[0] << std::endl;
		std::cout << "char: " << static_cast<char>(trimed_str[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(trimed_str[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(trimed_str[0]) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(trimed_str[0]) << std::endl;
		return ;
	}

	//Paresed string
	char *end = NULL;
	// Double is the largest and most flexible container; it can hold every possible int value and every possible float value without losing information.
	//strtod reconize nan nanf inf etc..
	double d = std::strtod(trimed_str.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
		return ;
	}
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
	return ;
}
