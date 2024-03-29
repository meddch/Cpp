/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:51:00 by mechane           #+#    #+#             */
/*   Updated: 2023/09/19 09:13:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


static const char	*dateValide(std::string dat)
{
    if (dat.size() != 10)
        return ("Error : Missing value.\n");

    for (int i = 0; i < 10; i++)
	{
        if (i != 4 && i != 7)
		{
            if (!isdigit(dat[i]))
                return ("Error : Bad date.\n");
		}
        else
		{
			if(dat[i] != '-')
            	return ("Error : Bad date.\n");
		}
    }

    int year, month, day;


    year = std::atoi(dat.substr(0, 4));
    month = std::atoi(dat.substr(5, 2));
    day = std::atoi(dat.substr(8, 2));


    if (year < 2009|| year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
        return ("Error : Bad date.\n");
	if (month == 2 && day > 28 && !(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0))
		return ("Error : Bad date.\n");

	int month_limits[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day > month_limits[month - 1])
		return ("Error : bad input (day) => ");

    return NULL;
}


static bool getCsv(std::ifstream& csv, std::map<std::string, double>& btc_map)
{
	std::string buffer;

	std::getline(csv, buffer);

	if (buffer != "date,exchange_rate")
		return std::cout << "ERROR: first line must begin with \"date,exchange_rate\"" << std::endl, true;

	while (std::getline(csv, buffer))
	{
		std::string date;
		std::string exchangeRate;
		std::istringstream iss(buffer);

		getline(iss, date, ',');
		const char *msg = dateValide(date);
		if (msg)
			return std::cout << msg << date << std::endl , true;
		getline(iss, exchangeRate, '\0');
		double exRate = std::strtod(exchangeRate.c_str(), NULL);
		if (exRate < 0)
			return std::cout << "ERROR: " << exchangeRate << " is an invalid exchange rate format" << std::endl, true;

		btc_map.insert(std::make_pair(date, exRate));
	}

	return false;
}


static bool is_str_digit(std::string value)
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]) && (value[i] != '.'|| (value.substr(i + 1)).find('.') != value.npos))
            return false;
	}
	return true;
}


static bool getInput(std::ifstream& input, std::map<std::string, double>& btc_map)
{
	std::string buffer;

	std::getline(input, buffer);
	if (buffer != "date | value")
		return std::cout << "ERROR: first line must begin with \"date | value\"" << std::endl, true ;


	BitcoinExchange	btc;
	while (std::getline(input, buffer))
	{
		std::string date;
		std::string value;
		std::string del;
		std::istringstream iss(buffer);
		std::string tmp;

		iss >> date >> del >> value >> tmp;


		const char *msg = dateValide(date);
		if (msg)
		{
			std::cout << "ERROR: bad date => " << date << std::endl;
			continue;
		}

		if (!is_str_digit(value) || !tmp.empty())
		{
			std::cout << "ERROR: bad value => " << value << std::endl;
			continue;
		}

		double v_value = std::strtod(value.c_str(), NULL);

		if (v_value < 0 || v_value > 1000)
		{
			std::cout << "ERROR: bad value : " << v_value << std::endl;
			continue;
		}

		if (del != "|")
		{
			std::cout << "ERROR: bad delimeter :" << del << std::endl;
			continue;
		}

		std::map< std::string, double >::iterator it_lowerDate = btc_map.lower_bound(date);

		if ( (*it_lowerDate).first != date )
		{
			if (it_lowerDate != btc_map.begin())
				it_lowerDate--;
		}

		btc.setDate(date);
		btc.setValue(v_value);
		btc.setExchangeRate((*it_lowerDate).second);

		btc.print();
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
		return std::cout << "ERROR: bad argument." << std::endl, EXIT_FAILURE;

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

	if (getCsv(data_Base, btc_map))
		return clean(inputFile, data_Base, EXIT_FAILURE) ;

	if (getInput(inputFile, btc_map))
		return clean(inputFile, data_Base, EXIT_FAILURE) ;

	return clean(inputFile, data_Base, EXIT_SUCCESS) ;
}
