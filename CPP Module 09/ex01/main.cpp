/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:52:44 by mechane           #+#    #+#             */
/*   Updated: 2023/09/08 18:20:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "RPN.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return std::cerr << "ERROR: invalid format\n  ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 \"" << std::endl, EXIT_FAILURE;

    try
	{
        std::cout << RPN::Calcul(av[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	
	return EXIT_SUCCESS; 
}