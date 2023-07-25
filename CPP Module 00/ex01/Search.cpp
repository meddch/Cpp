/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:59:13 by mechane           #+#    #+#             */
/*   Updated: 2023/07/25 08:51:50 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::Search(void)
{
	long long	choice;
	
	if (!_size)
	{
		std::cout << RED << "There's no contact !!\n";
			return ;
	}
	for (int i = 0;i < _size; i++)
	{
		std::cout << std::setw(10) << contacts[i].get_index() + 1 << " |";
		if (contacts[i].get_first_name().length() < 11)
			std::cout << std::setw(10) << contacts[i].get_first_name() << "|";
		else
			std::cout << std::setw(10) << contacts[i].get_first_name().substr(0,9) + "." << " |";
		if (contacts[i].get_last_name().length() < 11)
			std::cout << std::setw(10) << contacts[i].get_last_name() << " |";
		else
			std::cout << std::setw(10) << contacts[i].get_last_name().substr(0,9) + "." << "|";
		if (contacts[i].get_nick_name().length() < 11)
			std::cout << std::setw(10) << contacts[i].get_nick_name() << " |\n";
		else
			std::cout << std::setw(10) << contacts[i].get_nick_name().substr(0,9) + "." << "|\n";		  
	}
	std::cout << "Please enter valid contact :( between 1 and " 
			<< _size  << ") : \n" << A;
	while (std::cin.good())
	{
		choice = 0;
		if (std::cin >> choice)
		{
            if (choice <= _size && choice > 0)
    				break;
            else
               std::cout << "Please enter valid contact :( between 1 and " 
			<< _size  << ") : \n" << A;
		}
       	else
		{
            std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	if (!choice)
		exit(0);
	std::cout << D << "First name     : " << contacts[choice - 1].get_first_name() << std::endl;
	std::cout << "Last Name      : " << contacts[choice - 1].get_last_name() << std::endl;
	std::cout << "Nickname       : " << contacts[choice - 1].get_nick_name() << std::endl;
	std::cout <<"Phone Number   : " << contacts[choice - 1].get_phone_number() << std::endl;
	std::cout << "Darkest Secret : "<< contacts[choice - 1].get_darkest_secret() << std::endl;
}