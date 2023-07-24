/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:22:46 by mechane           #+#    #+#             */
/*   Updated: 2023/07/24 17:15:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::set_size(int i)
{
		_size = i;
}
const int	&PhoneBook::get_size(void)
{
	return (_size);
}

int main(void)
{
	PhoneBook	Pk;
	std::string	tmp;
	int			i = 0;
	
	std::cout << BLUE
	<< "*********************************************\n"
	<< 			 "  Welcome to the Awesome Phonebook Software\n"
	<< 			 "*********************************************\n\n"
	<< "Available Commands:\n"
	<< "  - ADD    : Add a contact to the phonebook\n"
	<< "  - SEARCH : Search for a contact in the phonebook\n"
	<< "  - EXIT   : Exit the phonebook software\\n";

	Pk.set_size(0);
	while(std::cin.good())
	{
		std::cout << BLUE << " Please enter a command (ADD, SEARCH, or EXIT): \n"
		<< "-> :" << WH;
		std::cin >> tmp;
		if (!tmp.compare("ADD"))
		{
			Pk.Add(i);
			i++;
			if (i > 7)
				i = 0;
			if (Pk.get_size() <= 8)
				Pk.set_size(Pk.get_size() + 1);
		}
		else if (!tmp.compare("SEARCH"))
			Pk.Search();
		else if (!tmp.compare("EXIT"))
			exit(0);
	}
		
}