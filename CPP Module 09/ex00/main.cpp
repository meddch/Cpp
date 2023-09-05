/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:51:00 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 18:51:14 by mechane          ###   ########.fr       */
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
	
	
	timeInfoChecker.tm_mday = day;
	timeInfoChecker.tm_mon = month - 1;
	timeInfoChecker.tm_year = year - 1900;
	
	std::mktime(&timeInfoChecker);
	if ( del1 != '-' || del2 != '-'
		|| timeInfoChecker.tm_mday != day
		|| timeInfoChecker.tm_mon != month - 1
		|| timeInfoChecker.tm_year != year - 1900 )
		return false ;
	return true ;
}

static bool getDataFromCsv(std::ifstream& input, std::map<std::string, double>& map_csv)
{
	std::string buffer;

	std::getline(input, buffer);
	if ( buffer != "date,exchange_rate" )
	{
		std::cout << "ERROR: invalid format: first line must begin with \"date,exchange_rate\"" << std::endl;
		return true ;
	}

	while ( std::getline(input, buffer) )
	{
		std::string gl_date;
		std::string gl_exchangeRate;
		std::istringstream iss(buffer);

		getline(iss, gl_date, ',');
		if ( isValidDate(gl_date) == false )
		{
			std::cout << "ERROR: " << gl_date << " is an invalid date format" << std::endl;
			return true ;
		}
		
		getline(iss, gl_exchangeRate, '\0');
		double exRate = std::strtod(gl_exchangeRate.c_str(), NULL);
		if ( exRate < 0 )
		{
			std::cout << "ERROR: " << gl_exchangeRate << " is an invalid exchange rate format" << std::endl;
			return true ;
		}
		
		map_csv.insert(std::pair<std::string, double>(gl_date, exRate));
	}
	
	return false ;
}

static bool getDataFromInput(std::ifstream& input, std::map<std::string, double>& map_csv)
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

		std::map< std::string, double >::iterator it_lowerDate = map_csv.lower_bound(gl_date);

		if ( (*it_lowerDate).first != gl_date )
		{
			if ( it_lowerDate != map_csv.begin() )
			{
				it_lowerDate--;
			}
		}
		btc.setValue(value);
		btc.setDate(gl_date);
		btc.setExchangeRate((*it_lowerDate).second);

		btc.printMultipledResult();
	}
	

	return false ;
}

static bool closeAndQuit(std::ifstream& inputFile, std::ifstream& dataBase, bool exitStatus)
{
	dataBase.close();
	inputFile.close();
	return exitStatus ;
}

int main ( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "ERROR: could not open file." << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream inputFile;

	inputFile.open(av[1], std::ifstream::in);
	if ( inputFile.is_open() == false )
	{
		std::cout << "ERROR: could not open file." << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream dataBase;

	dataBase.open("./data.csv", std::ifstream::in);
	if ( dataBase.is_open() == false )
	{
		std::cout << "ERROR: could not open the data base file." << std::endl;
		if ( inputFile.is_open() == true )
			inputFile.close();
		return EXIT_FAILURE ;
	}

	std::map< std::string, double >	map_csv;

	if ( getDataFromCsv(dataBase, map_csv) )
		return closeAndQuit(inputFile, dataBase, EXIT_FAILURE) ;

	if ( getDataFromInput(inputFile, map_csv) )
		return closeAndQuit(inputFile, dataBase, EXIT_FAILURE) ;

	return closeAndQuit(inputFile, dataBase, EXIT_SUCCESS) ;
}