/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:34:25 by mechane           #+#    #+#             */
/*   Updated: 2023/08/27 11:48:02 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinEchange.hpp"


int main(int ac , char **av)
{
	BitcoinEchange btc;

	if (ac != 2)
		return std::cerr << "Error: could not open file." << std::endl, 1;

	std::ifstream	input(av[1]);
	std::ifstream	db("data.csv");

	if(input.fail() || db.fail())
		return std::cerr << "Error: could not open file." << std::endl, 1;

	
}