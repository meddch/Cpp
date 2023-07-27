/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:20:28 by mechane           #+#    #+#             */
/*   Updated: 2023/07/27 10:45:44 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	
	std::string		string = "HI THIS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Address of string                  : " << &string << std::endl;
	std::cout << "Address held by stringPTR          : " << stringPTR << std::endl;
	std::cout << "Address held by string stringREF   : " << &stringREF << std::endl;
	
	std::cout << "Value of string                    : " << string << std::endl;
	std::cout << "Value pointed by stringPTR         : " << *stringPTR << std::endl;
	std::cout << "Addres pointed by string stringREF : " << stringREF << std::endl;
	
	
}