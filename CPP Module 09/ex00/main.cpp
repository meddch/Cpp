/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:51:00 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 20:49:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


static bool isValidDate(std::string date)
{
	std::istringstream iss(date);
	int year;
	int month;
	int day;
	char del1;
	char del2;

	std::tm timeInfoChecker = {};
	
	iss >> year >> del1 >> month >> del2 >> day;
	
	
	timeInfoChecker.tm_year = year - 1900;
	timeInfoChecker.tm_mon = month - 1;
	timeInfoChecker.tm_mday = day;
	
	std::mktime(&timeInfoChecker);
	if ( del1 != '-' || del2 != '-'
		|| timeInfoChecker.tm_year != year - 1900
		|| timeInfoChecker.tm_mon != month - 1
		|| timeInfoChecker.tm_mday != day)
		{
			printf("%d %d",day, timeInfoChecker.tm_mday);
		return false ;
		}
	return true ;
}

static bool getDataFromCsv(std::ifstream& input, std::map<std::string, double>& btc_map)
{
	std::string buffer;

	std::getline(input, buffer);
	if (buffer != "date,exchange_rate" )
		return std::cout << "ERROR: invalid format: first line must begin with \"date,exchange_rate\"" << std::endl, true;

	while (std::getline(input, buffer))
	{
		std::string gl_date;
		std::string gl_exchangeRate;
		std::istringstream iss(buffer);

		getline(iss, gl_date, ',');
		if (!isValidDate(gl_date))
			return std::cout << "ERROR: " << gl_date << " is an invalid date format" << std::endl, true;
		
		getline(iss, gl_exchangeRate, '\0');
		double exRate = std::strtod(gl_exchangeRate.c_str(), NULL);
		if (exRate < 0)
			return std::cout << "ERROR: " << gl_exchangeRate << " is an invalid exchange rate format" << std::endl, true;
		
		btc_map.insert(std::make_pair(gl_date, exRate));
	}
	
	return false;
}

static bool getDataFromInput(std::ifstream& input, std::map<std::string, double>& btc_map)
{
	std::string buffer;

	std::getline(input, buffer);
	if ( buffer != "date | value" )
	{
		std::cout << "ERROR: invalid format: first line must begin with \"date | value\"" << std::endl;
		return true ;
	}

	
	BitcoinExchange	btc;
	while ( std::getline(input, buffer) )
	{
		std::string gl_date;
		std::string gl_value;
		std::string del;
		std::istringstream iss(buffer);

		iss >> gl_date >> del >> gl_value;

		if ( isValidDate(gl_date) == false )
		{
			std::cout << "ERROR: bad input => " << gl_date << std::endl;
			continue ;
		}
		
		double value = std::strtod(gl_value.c_str(), NULL);
		if ( value <= 0 )
		{
			std::cout << "ERROR: not a positive number." << std::endl;
			continue ;
		}
		if ( 1000 <= value )
		{
			std::cout << "ERROR: too large a number." << std::endl;
			continue ;
		}
		if (del != "|")
		{
			std::cout << "It's not a correct delimeter." << std::endl;
			continue ;
		}

		std::map< std::string, double >::iterator it_lowerDate = btc_map.lower_bound(gl_date);

		if ( (*it_lowerDate).first != gl_date )
		{
			if ( it_lowerDate != btc_map.begin() )
				it_lowerDate--;
		}
		btc.setValue(value);
		btc.setDate(gl_date);
		btc.setExchangeRate((*it_lowerDate).second);

		btc.printMultipledResult();
	}
	

	return false ;
}

static bool clean(std::ifstream& inputFile, std::ifstream& data_Base, bool exitStatus)
{
	data_Base.close();
	inputFile.close();
	return exitStatus ;
}

int main (int ac, char **av)
{
	if (ac != 2)
		return std::cout << "ERROR: could not open file." << std::endl, EXIT_FAILURE;

	std::ifstream inputFile;

	inputFile.open(av[1]);
	
	if (inputFile.fail())
		return std::cout << "ERROR: could not open file." << std::endl, EXIT_FAILURE;

	std::ifstream data_Base;

	data_Base.open("./data.csv");
	
	if (data_Base.fail())
	{
		std::cout << "ERROR: could not open the data base file." << std::endl;
		if (inputFile.is_open())
			inputFile.close();
		return EXIT_FAILURE ;
	}

	std::map< std::string, double >	btc_map;

	if (getDataFromCsv(data_Base, btc_map))
		return clean(inputFile, data_Base, EXIT_FAILURE) ;

	if (getDataFromInput(inputFile, btc_map))
		return clean(inputFile, data_Base, EXIT_FAILURE) ;

	return clean(inputFile, data_Base, EXIT_SUCCESS) ;
}