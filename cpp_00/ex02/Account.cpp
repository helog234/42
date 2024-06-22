/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:33:28 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/22 11:30:26 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"
#include <ctime>
#include <iomanip> 

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex << ";";
	std::cout << "amount:";
	std::cout << _amount << ";";
	this->_totalAmount += initial_deposit;
	std::cout << "created" << std::endl;
}

Account::Account( void ) 
{
	_accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 1;
	_nbWithdrawals	= 0;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex << ";";
	std::cout << "amount:";
	std::cout << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	int	nbAccounts = getNbAccounts();
	_displayTimestamp();
	std::cout << " accounts:";
	std::cout << nbAccounts << ";";
	std::cout << "total:";
	std::cout << getTotalAmount() << ";";
	std::cout << "deposits:";
	std::cout << getNbDeposits() << ";";
	std::cout << "withdrawals:";
	std::cout << getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex << ";";
	std::cout << "p_amount:";
	std::cout << _amount << ";";
	std::cout << "deposit:";
	if (deposit < 0)
	{
		std::cout << "refused" << std::endl;
		return ;
	}
	std::cout << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:";
	std::cout << _amount << ";";
	std::cout << "nb_deposits:";
	std::cout << _nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
		std::cout << " index:";
		std::cout << _accountIndex << ";";
		std::cout << "p_amount:";
		std::cout << _amount << ";";
		std::cout << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:";
	std::cout << _amount << ";";
	std::cout << "nb_withdrawals:";
	std::cout << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex << ";";
	std::cout << "amount:";
	std::cout << _amount << ";";
	std::cout << "deposits:";
	std::cout << _nbDeposits << ";";
	std::cout << "withdrawals:";
	std::cout << _nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm* now_tm = std::localtime(&now);
	std::cout << "[" << (now_tm->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill ('0');
	std::cout << (now_tm->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill ('0');
	std::cout << (now_tm->tm_mday);
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill ('0');
	std::cout << (now_tm->tm_hour);
	std::cout << std::setw(2) << std::setfill ('0');
	std::cout << (now_tm->tm_min);
	std::cout << std::setw(2) << std::setfill ('0');
	std::cout << (now_tm->tm_sec);
	std::cout << "]";
	return ;
}

