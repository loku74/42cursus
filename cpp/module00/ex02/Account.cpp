#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

int	Account::checkAmount(void) const { return _amount; }

void	Account::_displayTimestamp(void)
{
	char		timeBuffer[100];
	std::time_t	now;

	now = std::time(NULL);
	std::tm *localTime = std::localtime(&now);

	std::strftime(timeBuffer, 100, "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << timeBuffer;
}

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout <<
			  "index:" << _accountIndex
			  << ";amount:" << _amount << ";created"
			  << std::endl;
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout <<
			  "index:" << _accountIndex
			  << ";amount:" << _amount << ";closed"
			  << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout <<
	"accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" <<_totalNbWithdrawals
	<< std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<
	"index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout <<
	"index:" << _accountIndex
	<< ";p_amount:" << _amount - deposit
	<< ";deposit:" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout <<
	"index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";withdrawal:";

	if (checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;

	std::cout << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	return (true);
}