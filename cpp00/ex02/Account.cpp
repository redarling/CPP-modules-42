#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
    std::cout.flush();
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

Account::~Account(void)
{
    this->_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    this->_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ';'
              << "deposit:" << deposit << ";"
              << "amount:" << _amount + deposit << ';'
              << "nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (checkAmount() < withdrawal)
    {
        this->_displayTimestamp();
        std::cout << " index:" << _accountIndex << ";"
                  << "p_amount:" << _amount << ';'
                  << "withdrawal:refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    this->_displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ';'
              << "withdrawal:" << withdrawal << ";"
              << "amount:" << _amount - withdrawal << ';'
              << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount -= withdrawal;
    return (true);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout << " index:" << _accountIndex << ';'
              << "amout:" << _amount << ';'
              << "deposits:" << _nbDeposits << ';'
              << "withdrawals:" << _nbWithdrawals << std::endl;
    std::cout.flush();
}

void	Account::_displayTimestamp(void)
{
    std::time_t now;
    std::tm*    localTime;
    
    now = std::time(nullptr);
    localTime = std::localtime(&now);
    std::cout << '[' 
              << std::put_time(localTime, "%Y%m%d_%H%M%S") 
              << ']';
}