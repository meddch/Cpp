/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:21:47 by mechane           #+#    #+#             */
/*   Updated: 2023/07/25 15:04:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

//strftime 

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals= 0;

// Constarctor
Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";created\n";
	
}
// Destractor
Account::~Account( void )
{
	_displayTimestamp();
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	
	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount << ";closed\n";
}



void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ":deposits:";
	
	if (deposit > 0)
	{
		std::cout << deposit;
		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		

		std::cout << ";amount:";
		std::cout << this->_amount;
		std::cout << ";nb_deposits:";
		std::cout << this->_nbDeposits;
		std::cout << std::endl;
		
		return;
	}
	std::cout << "refused\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ";withdrawal:";
	if (this->checkAmount() && (this->_amount - withdrawal > 0))
	{
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		

		std::cout << ";amount:";
		std::cout << this->_amount;
		std::cout << ";nb_withdrawals:";
		std::cout << this->_nbWithdrawals;
		std::cout << std::endl;
		
		return true;
	}
	std::cout << "refused\n";
	return false;
}

void	Account::_displayTimestamp(void)
{
	time_t current;
	struct tm *time_inf;
	char	buf[18];
	
	time(&current);
	time_inf = localtime(&current);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", time_inf);
	std::cout << buf;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}


int	Account::checkAmount(void) const
{
	if (this->_amount > 0)
		return 1;
	return 0;
}
// Getters
int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}
int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}
int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}