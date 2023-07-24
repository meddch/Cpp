/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:58:45 by mechane           #+#    #+#             */
/*   Updated: 2023/07/24 17:06:36 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::Add(int i)
{
	std::string tmp;
	
	tmp.clear();
	std::cin.ignore();
	while (tmp.empty() && std::cin.good())
	{
		std::cout << GREEN << "Please enter the first name :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	tmp.clear();
	while (tmp.empty() && std::cin.good())
	{
		std::cout<< GREEN  << "Please enter the last name :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_last_name(tmp);
	tmp.clear();
	while (tmp.empty() && std::cin.good())
	{
		std::cout << GREEN << "Please enter the nick name :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_nick_name(tmp);
	tmp.clear();
	while (tmp.empty() && std::cin.good())
	{
		std::cout << GREEN << "Please enter the phone number :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_phone_number(tmp);
	tmp.clear();
	while (tmp.empty() && std::cin.good())
	{
		std::cout << GREEN << "Please enter the darkest secret :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_darkset_secret(tmp);
	contacts[i].set_index(i);
	std::cout << GREEN << "Contact saved successfully.\n";
}