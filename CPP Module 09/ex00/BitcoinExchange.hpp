/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:51:20 by mechane           #+#    #+#             */
/*   Updated: 2023/09/08 16:43:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <string.h>
# include <map>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <sstream>

class BitcoinExchange
{
		double		_value;
		double		_exRate;
		std::string	_date;

public:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	setDate(std::string _date);
	void	setValue(double _value);
	void	setExchangeRate(double _exRate);
	void	print() const;
};
