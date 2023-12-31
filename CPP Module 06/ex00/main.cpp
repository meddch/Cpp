/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:26:40 by mechane           #+#    #+#             */
/*   Updated: 2023/08/21 14:06:52 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int ac , char **av)
{
	if (ac != 2)
		return 1;
	std::string s = av[1];
	ScalarConverter::convert(s);

	return 0;
}