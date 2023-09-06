/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:51:00 by mechane           #+#    #+#             */
/*   Updated: 2023/09/06 13:58:33 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


static const char	*dateValide(std::string dat)
{
	char	*ptr;
	int		month;
	int		day;
	int		year;
	char	*date = (char *)dat.c_str();

	if (!date)
		return ("Error : Missing value.\n");
	ptr = strtok(date, "-");
	year = std::atoi(ptr);

	ptr = strtok(NULL, "-");
	month = std::atoi(ptr);
	if (!ptr || month < 1 || month > 12)
		return ("Error : bad input (month) =>");

	ptr = strtok(NULL, "-");
	day = std::atoi(ptr);
	int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (!ptr || day > month_limits[month - 1] || day < 1)
		return ("Error : bad input (day) =>");
	
	if (month == 2 && year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0 && day > 28)
			return ("Error : bad input (day) =>");
		else if (year % 4 == 0 && day > 29)
			return ("Error : bad input (day) =>");
	}
	if (month == 8 && day > 31)
		return ("Error : bad input (day) =>");
	return (NULL);
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
		const char *msg = dateValide(gl_date);
		if (msg)
			return std::cout << msg << std::endl , true;
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
		printf("%s\n",buffer.c_str());
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

		
		const char *msg = dateValide(gl_date);
		if (msg)
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
		
		btc.setDate(gl_date);
		btc.setValue(value);
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

	data_Base.open("data.csv");
	
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