/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:52:44 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 18:52:45 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

static bool isValidArg(char *av)
{
	int count_number = 0;
	int count_operator = 0;
	int i = 0;

	while ( av[i] != '\0' )
	{
		if ( av[i] == ' ' )
		{
			i++;
			continue ;
		}
		
		if ( av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/' )
		{
			count_operator++;
		}
		else if ( '0' <= av[i] && av[i] <= '9' )
		{
			if ( '0' <= av[i + 1] && av[i + 1] <= '9' )
			{

				std::cout << "the numbers need to be less than 10" << std::endl;
				return false ;
			}
			count_number++;
		}
		else
		{
			std::cout << "the arg must be +-/* operator or a number between 0 and 9" << std::endl;
			return false ;
		}
		
		i++;
	}

	if ( count_number - 1 == count_operator )
		return true ;

	std::cout << "invalid arg" << std::endl;
	return false ;
}

int main(int ac, char **av)
{
	if ( ac != 2 )
	{
		std::cout << "Bad arguments" << std::endl;
		return EXIT_FAILURE ;
	}
	
	if ( isValidArg(av[1]) == false )
		return EXIT_FAILURE ;
	
	RPN rpn;
	
	if ( rpn.calculate(av[1]) == false )
		return EXIT_FAILURE ;

	std::cout << rpn.getResult() << std::endl;

	return EXIT_SUCCESS ;
}