#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
int Account::checkAmount(void) const { return _amount; }

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

/* [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0 */
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << 
		"accounts:" << getNbAccounts() << 
		";total:" << getTotalAmount() <<
		";deposits:" << getNbDeposits() <<
		";withdrawals:" << getNbWithdrawals() << std::endl;
}

/* [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0 */
void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << 
		"index:" << _accountIndex << 
		";amount:" << _amount << 
		";deposits:" << _nbDeposits<<
		";withdrawals:" << _nbWithdrawals <<std::endl;
}

/* [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 */
void Account::makeDeposit(int deposit) {
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << 
		"index:" << _accountIndex << 
		";p_amount:" << checkAmount() << 
		";deposit:" << deposit <<
		";amount:" << _amount + deposit <<
		";nb_deposits:" << _nbDeposits <<std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

/*
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << 
		"index:" << _accountIndex << 
		";p_amount:" << checkAmount() << 
		";withdrawal:"; 
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal <<
		";amount:" << checkAmount() - withdrawal << 
		";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}
