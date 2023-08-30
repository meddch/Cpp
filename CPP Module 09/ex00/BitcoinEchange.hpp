/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinEchange.hpp                                 :+:      :+:    :+:   */
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

class BitcoinEchange
{
	std::map<int, float, std::greater<int> > _info;
	public:
		BitcoinEchange();
		BitcoinEchange(const BitcoinEchange &copy);
		~BitcoinEchange();
		BitcoinEchange & operator=(const BitcoinEchange &assign);

};
