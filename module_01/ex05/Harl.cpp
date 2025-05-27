#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "DEBUG LEVEL:" << std::endl;
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO LEVEL:" << std::endl;
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING LEVEL:" << std::endl;
	std::cout << WARN_MSG << std::endl;
}

void Harl::error(void) {
	std::cout << "ERROR LEVEL:" << std::endl;
	std::cout << ERROR_MSG << std::endl;
}

static int type_string(std::string level)
{
	if (level == "DEBUG") return DEBUG;
	if (level == "INFO") return INFO;
	if (level == "WARNING") return WARN;
	if (level == "ERROR") return ERROR;
	return NO_LEVEL;

}

void Harl::complain(std::string level) {
	void (Harl::*fp)(void);

	switch (type_string(level))
	{
	case DEBUG:
		fp = &Harl::debug;
		break;
	case INFO:
		fp = &Harl::info;
		break;
	case WARN:
		fp = &Harl::warning;
		break;
	case ERROR:
		fp = &Harl::error;
		break;
	default:
		std::cout <<  "No Level: Error" << std::endl;
		return;
	}
	(this->*fp)();
}
