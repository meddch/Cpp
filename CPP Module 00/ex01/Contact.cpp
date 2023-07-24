/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:29:38 by mechane           #+#    #+#             */
/*   Updated: 2023/07/24 17:13:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(std::string str)
{
	_first_name = str;
}

void Contact::set_last_name(std::string str)
{
	_last_name = str;
}

void Contact::set_nick_name(std::string str)
{
	_nick_name = str;
}

void Contact::set_phone_number(std::string str)
{
	_phone_number = str;
}

void Contact::set_darkset_secret(std::string str)
{
	_darkest_secret = str;
}
void Contact::set_index(int i)
{
	_index = i;
}

const std::string &Contact::get_first_name(void)
{
	return (_first_name);
}

const std::string &Contact::get_last_name(void)
{
	return (_last_name);
}

const std::string &Contact::get_nick_name(void)
{
	return (_nick_name);
}

const std::string &Contact::get_phone_number(void)
{
	return (_phone_number);
}

const std::string &Contact::get_darkest_secret(void)
{
	return (_darkest_secret);
}
const int &Contact::get_index(void)
{
	return (_index);
}