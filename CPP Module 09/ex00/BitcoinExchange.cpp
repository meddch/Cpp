/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:50:03 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 20:02:50 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _value(0), _exRate(0), _date("") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_date = other._date;
		this->_value = other._value;
		this->_exRate = other._exRate;
	}
	
	return *this ;
}

void	BitcoinExchange::setDate(std::string date)
{
	_date = date;
}

void	BitcoinExchange::setValue(double value)
{
	_value = value;
}

void	BitcoinExchange::setExchangeRate(double exRate)
{
	_exRate = exRate;
}

void	BitcoinExchange::printMultipledResult() const
{
	std::cout << _date << " => " << _value << " = " << _value * _exRate << std::endl;
}