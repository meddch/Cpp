/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:33:16 by mechane           #+#    #+#             */
/*   Updated: 2023/08/30 09:39:50 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <vector>

class BitcoinExchange
{
	std::map<std::string, double, std::greater<int> > _info;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		bool isvalid(std::ifstream &file);
		void Data_Base(std::ifstream database);

};
