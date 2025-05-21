#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

Account::Account( int initial_deposit )
	: _accountIndex (_nbAccounts++)
	, _amount (initial_deposit)
	, _nbDeposits (0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/* [19920104_091532] [YearMonthDate_HourMinSec]*/
void Account::_displayTimestamp(void) {

	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char output[50];
	strftime(output, 50, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << 
		"accounts:" << getNbAccounts() << 
		";total:" << getTotalAmount() <<
		";deposits:" << getNbDeposits() <<
		";withdrawals:" << getNbWithdrawals() << std::endl;
}
