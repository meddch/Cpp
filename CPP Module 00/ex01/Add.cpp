/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:58:45 by mechane           #+#    #+#             */
/*   Updated: 2023/07/25 08:35:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	all_space(std::string tmp);
bool	all_digit(std::string tmp);

void	PhoneBook::Add(int i)
{
	std::string tmp;
	
	tmp.clear();
	std::cin.ignore();
	while (std::cin.good() && all_space(tmp))
	{
		std::cout << GREEN << "Please enter the first name :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	tmp.clear();
	while (std::cin.good() && all_space(tmp))
	{
		std::cout<< GREEN  << "Please enter the last name :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_last_name(tmp);
	tmp.clear();
	while (std::cin.good() && all_space(tmp))
	{
		std::cout << GREEN << "Please enter the nick name :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_nick_name(tmp);
	tmp.clear();
	while (std::cin.good() && !all_digit(tmp))
	{
		std::cout << GREEN << "Please enter the phone number :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_phone_number(tmp);
	tmp.clear();
	while (std::cin.good() && all_space(tmp))
	{
		std::cout << GREEN << "Please enter the darkest secret :\n" << D;
		std::getline(std::cin, tmp);
	}
	contacts[i].set_darkset_secret(tmp);
	contacts[i].set_index(i);
	if (std::cin.good())
		std::cout << GREEN << "Contact saved successfully.\n";
}


bool	all_space(std::string tmp)
{	
	for(int i=0; i < (int)tmp.length() ; i++)
		if (tmp[i] != ' ')
			return false;
	return true;
}

bool	all_digit(std::string tmp)
{
	if (tmp.empty())
		return false;
	for(int i=0; i < (int)tmp.length() ; i++)
		if (! std::isdigit(tmp[i]))
			return false;
	return true;
}