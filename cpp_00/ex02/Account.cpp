/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:33:28 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/21 12:09:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"
#include <ctime>
#include <iomanip> 

Account::Account( int initial_deposit ) : _amount(initial_deposit) {}
Account::Account( void ) : _accountIndex(1) {}
Account::~Account( void ){}

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
	_displayTimestamp();
	std::cout << " accounts:";
	std::cout << getNbAccounts() << ";";
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
	this->_amount = deposit;
	this->_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal == 0)
		return (false);
	this->_amount = withdrawal;
	this->_totalAmount -= withdrawal;
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

