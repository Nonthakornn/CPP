#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	: _accountIndex (_nbAccounts++)
	, _amount (initial_deposit)
	, _nbDeposits (0)
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// void Account::displayAccountsInfos() {

// }
