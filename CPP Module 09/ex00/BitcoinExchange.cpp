/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:33:48 by mechane           #+#    #+#             */
/*   Updated: 2023/08/27 10:34:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
}


BitcoinExchange::~BitcoinExchange()
{
}


BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}

bool BitcoinExchange::isvalid(std::ifstream &file)
{
	std::string header;
    
	std::getline(file, header);
	if (header != "date | value")
		return false;
	return true;
}


bool isLeap(int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool validDate(std::string &date) {
    // valid date example: 2012-01-11
    
    if (date.size() != DATE_SZ)
        return false;

    for (int i = 0; i < DATE_SZ; i++) {
        if (i != 4 && i != 7) {
            if (!isdigit(date[i]))
                return false;
        } else if (date[i] != '-') {
            return false;
        }
    }

    int yr, mth, day;
    yr = std::stoi(date.substr(0, 4));
    mth = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));

    // this part bellow is inspired by https://www.geeksforgeeks.org/program-check-date-valid-not/
    if (yr < MN_YR || yr > MX_YR || mth < 1 || mth > 12 || day < 1 || day > 31)
        return false;

    if (mth == 2 && (day > 29 || (!isLeap(yr) && day > 28)))
        return false;
    
    if ((mth == 4 || mth == 6 || mth == 9 || mth == 11) && day > 30)
        return false;

    return true;
}

double convert(std::string &date, double amt) {
    std::map<std::string, double>::iterator it = btcPrices.lower_bound(date);
    
    // all dates in database are lower than the given date
    if (it == btcPrices.end())
        return amt * btcPrices.rbegin()->second;
    
    // date exists or all dates in database are higher than the given date
    if (it->first == date || it == btcPrices.begin())
        return amt * it->second;
    
    // a date lesser than the given one exists
    return amt * (--it)->second;
}

std::string handle(std::stringstream &query, std::string &squery) {
    std::string date, delim, amount, rest;
    
    if (!(query >> date) || !(query >> delim) || !(query >> amount) || (query >> rest)) {
        return "Error: bad query => " + squery;
    }

    if (!validDate(date)) {
        return "Error: invalid date => " + date;
    }

    if (delim != "|") {
        return "Error: bad query => " + squery;
    }

    size_t idx;
    double amt = std::stod(amount, &idx);

    if (idx != amount.size() || amt > 1000. || amt < 0.) {
        return "Error: invalid amount => " + amount;
    }

    return date + " => " + amount + " = " + std::to_string(convert(date, amt));
}

void  BitcoinExchange::Data_Base(std::ifstream database)
{
    std::string keyVal;

    // ignore header
    std::getline(database, keyVal);

    // parse
    while (getline(database, keyVal))
    {
        if (keyVal.find(',') == keyVal.npos)
	        throw std::runtime_error ("invalid line");
        std::string key = keyVal.substr(0, 10);
        std::string val = keyVal.substr(10 + 1);
        _info[key] = strtod();
    }
}


int BitcoinExchange::Parsing(int year, int month, int day, std::string raate ,float rate, std::string line)
{
    size_t idx = line.find("|");
    if (line[idx + 1] != ' ' || line[idx - 1] != ' ')
    {
        std::cerr << "Invalid Pipe\n";
        return (-1);
    }

    if (line.substr(4,1) != "-" && line.substr(7,1) != "-")
    {
        std::cerr << "Invalid Date Format\n";
        return (-1);
    }

    int count = 0;
    for (size_t i = 0; i < raate.length(); i++)
    {
        if (raate[0] == '.')
        {
            std::cerr << "Invalid Rate Format\n";
            return (-1);
        }
        if (raate[i] == '.')
            count++;
        if (!(isdigit(raate[i])) && raate[i] != '.' && (count == 1 || count == 0))
        {
            std::cerr << "Invalid Rate Format\n";
            return (-1);
        }
    }

    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year < 2009 || month < 1 || month > 12)
    {
        std::cerr << "Invalid Date Format\n";
        return (-1);
    }
    if (day > month_limits[month - 1] || day < 1)
    {
        std::cerr << "Out of month range\n";
        return (-1);
    }
    if (rate < 0.00 || rate > 1000.00 )
    {
        std::cerr << "Rate out of range\n";
        return (-1);
    }
    return (0);
}

void    BitcoinExchange::PrintOuput(std::string inputdate, float bitcoins)
{
    std::map<std::string, float>::iterator itb = this->_database.begin();
    std::map<std::string, float>::iterator ite = this->_database.end();
    bool    flag = false;

    for (; itb != ite; itb++)
    {
        if (itb->first == inputdate)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " <<  std::fixed << std::setprecision(2) << bitcoins * itb->second << "\n";
        flag = false;
    }
    else
    {
        ite = this->_database.lower_bound(inputdate);
        std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " << std::fixed << std::setprecision(2) << bitcoins * ite->second << "\n";
    }
}

void    BitcoinExchange::ReadInput(std::string file)
{
    std::ifstream   input;
    std::string     line;

    input.open(file);

    if (input.fail())
    {
        std::cerr << "Cannot Open File\n";
        input.close();    
        exit(0);
    }

    while (!input.eof())
    {
        std::string fulldate;
        std::getline(input, line);

        int year, month, day = 0;
        std::stringstream y, m, d;
        y << line.substr(0,4);
        m << line.substr(5,2);
        d << line.substr(8,2);
        y >> year;
        m >> month;
        d >> day;

        if (line.length() < 14)
        {
            std::cerr << "Invalid Format\n";
            continue ;
        }
        
        std::string raate = line.substr(13, line.find('\0'));

        float   bitcoins = 0.00;
        std::stringstream bit;
        bit << raate;
        bit >> bitcoins;

        if (month < 10 && day < 10)
            fulldate = std::to_string(year * 10) + std::to_string(month * 10) + std::to_string(day);
        else if (day < 10)
            fulldate = std::to_string(year) + std::to_string(month * 10) + std::to_string(day);
        else if (month < 10)
            fulldate = std::to_string(year * 10) + std::to_string(month) + std::to_string(day);
        else
            fulldate = std::to_string(year) + std::to_string(month) + std::to_string(day);

        if (Parsing(year, month, day, raate, bitcoins, line) == 0)
            PrintOuput(fulldate, bitcoins);
    }
}
