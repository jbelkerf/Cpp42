# include "Account.hpp"

// Define static variables (allocate storage)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Define the static function
void Account::_displayTimestamp() {
    // for example:
    std::cout << "[19920104_091532] ";
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
