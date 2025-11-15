/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:44:55 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/11/15 11:12:23 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);
    std::tm *t = std::localtime(&now);

    std::string s;

    s = "[";
    s += std::string(8, '0');
    int year = t->tm_year + 1900;
    s[1] = '0' + (year / 1000) % 10;
    s[2] = '0' + (year / 100) % 10;
    s[3] = '0' + (year / 10) % 10;
    s[4] = '0' + (year % 10);

    s[5] = '0' + (t->tm_mon + 1) / 10;
    s[6] = '0' + (t->tm_mon + 1) % 10;
    s[7] = '0' + t->tm_mday / 10;
    s[8] = '0' + t->tm_mday % 10;
    s += "_";
    s += std::string(6, '0');
    s[10] = '0' + t->tm_hour / 10;
    s[11] = '0' + t->tm_hour % 10;
    s[12] = '0' + t->tm_min / 10;
    s[13] = '0' + t->tm_min % 10;
    s[14] = '0' + t->tm_sec / 10;
    s[15] = '0' + t->tm_sec % 10;
    s += "] ";
    std::cout << s;
}

int	Account::getNbAccounts( void ){
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
    return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ){
    return Account::_totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    _accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    _amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits += 1;
    //-[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits +=1;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    if (_amount >= withdrawal)
    {
        _nbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals += 1;
        // [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _amount -= withdrawal;
        return true;
    }
    else
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }

}
int		Account::checkAmount( void ) const
{
    return _amount;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
