/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:58:45 by mechane           #+#    #+#             */
/*   Updated: 2023/07/24 12:22:52 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::Add(void)
{
	std::string tmp;
	
	tmp.clear();
	while (tmp.empty())
	{
		std::cout << "Please enter the first name :\n";
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	tmp.clear();
	while (tmp.empty())
	{
		std::cout << "Please enter the last name :\n";
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	tmp.clear();
	while (tmp.empty())
	{
		std::cout << "Please enter the nick name :\n";
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	tmp.clear();
	while (tmp.empty())
	{
		std::cout << "Please enter the phone number :\n";
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	tmp.clear();
	while (tmp.empty())
	{
		std::cout << "Please enter the darkest secret :\n";
		std::getline(std::cin, tmp);
	}
	contacts[i].set_first_name(tmp);
	contacts[i].index = i;
}