#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		this->_database = src._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Removes whitespace from front and back
std::string BitcoinExchange::_trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

// Validates YYYY-MM-DD format 
bool BitcoinExchange::_isValidDate(const std::string& date) {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	int year, month, day;
	char dash1, dash2;
	std::istringstream ss(date);

	// Parsing 
	if (!(ss >> year >> dash1 >> month >> dash2 >> day)) return false;

	// Logical checks
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;

	// Simple days in month check
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
	if (month == 2) {
		// Leap year calculation
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28)) return false;
	}
	return true;
}

// Validates  0 <= value <= 1000
bool BitcoinExchange::_isValidValue(const float& value) {
	return (value >= 0.0f && value <= 1000.0f);
}


void BitcoinExchange::loadDatabase(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw DatabaseException();

	std::string line;
	// Skip header line "date,exchange_rate"
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rateStr;
		
		// Parse CSV format: date,rate
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
			float rate = static_cast<float>(std::strtod(rateStr.c_str(), NULL));
			_database[date] = rate;
		}
	}
	file.close();
}

float BitcoinExchange::_getExchangeRate(const std::string& date) {
	// std::map::lower_bound returns the first key that is >= date
	std::map<std::string, float>::iterator it = _database.lower_bound(date);

	// Case 1: Exact match
	if (it != _database.end() && it->first == date)
		return it->second;

	// Case 2: No exact match.
	// If it == begin(), the requested date is older than our entire database.
	if (it == _database.begin())
		return -1.0f; // Indicator for "no valid date found"

	// Case 3: We are at a date > requested, so we step back one to find the closest LOWER date.
	--it;
	return it->second;
}

void BitcoinExchange::processInput(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	// Skip header "date | value"
	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty()) continue;
		size_t pipePos = line.find('|');

		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = _trim(line.substr(0, pipePos));
		std::string valueStr = _trim(line.substr(pipePos + 1));

		if (!_isValidDate(dateStr)) {
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		char* end;
		double value = std::strtod(valueStr.c_str(), &end);

		// Check if strtod failed to convert anything or if garbage remains
		if (valueStr.empty() || *end != '\0') {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = _getExchangeRate(dateStr);
		if (rate < 0) {
			// This happens if the date is before the very first entry in data.csv
			std::cerr << "Error: date too early, no data available." << std::endl;
		} else {
			std::cout << dateStr << " => " << value << " = " << (value * rate) << std::endl;
		}
	}
	file.close();
}
