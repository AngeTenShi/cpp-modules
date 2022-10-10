#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	return ;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts();
   Account::_totalAmount += initial_deposit;
	this->_displayTimestamp();
	this->displayStatus();
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
   return ;
}

Account::~Account(void)
{
    Account::_nbAccounts--;
}

int Account::getNbAccounts()
{
    return Account::_nbAccounts;
}

int Account::getNbDeposits()
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return Account::_totalNbWithdrawals;
}

int Account::getTotalAmount()
{
    return Account::_totalAmount;
}

void Account::makeDeposit(int deposit)
{
    if (deposit <= 0)
        return ;
    Account::_totalAmount += deposit;
	 this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	return (true);
}

int Account::checkAmount(void) const 
{
    return (1);
}

void Account::displayStatus(void) const
{
    std::cout << "index:"<< this->_accountIndex << ";";
	 std::cout << "amount:" << this->_amount << ";";
}

void Account::_displayTimestamp()
{
	time_t time = std::time(nullptr);
	struct tm timer = *std::localtime(&time);
	std::cout << "[" << timer.tm_year + 1900
				 << timer.tm_mon + 1 << timer.tm_mday << "_" << timer.tm_hour
				 << timer.tm_min << timer.tm_sec << "] ";
}
&
int main()
{
	Account acc(300);
	Account acca(750);
	Account accav(45600);
}