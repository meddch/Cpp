/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:51:20 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 18:54:14 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class BitcoinExchange
{
	private:

		double		value;
		double		exRate;
		std::string	date;

	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void	setDate(std::string _date);
		void	setValue(double _value);
		void	setExchangeRate(double _exRate);

		void	printMultipledResult() const;
};
