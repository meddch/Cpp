/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:20:28 by mechane           #+#    #+#             */
/*   Updated: 2023/07/26 14:45:24 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	
	std::string		string = "HI THIS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "address of string : " << &string << std::endl;
	std::cout << "address held by stringPTR : " << &stringPTR << std::endl;
	std::cout << "address held by string stringREF :" << &stringREF << std::endl;
	
	std::cout << "value of string : " << string << std::endl;
	std::cout << "value pointed by stringPTR : " << stringPTR << std::endl;
	std::cout << "addres pointed by string stringREF :" << stringREF << std::endl;
	
	
}