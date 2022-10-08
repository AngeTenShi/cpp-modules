#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_displayTimestamp();
    this->displayAccountsInfos();
    this->displayStatus();
    return ;
}

Account::~Account(void)
{
    return ;
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
    this->_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount(void) const 
{
    return (1);
}

void Account::displayStatus(void) const
{
    return (1);
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;