/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:34:26 by mechane           #+#    #+#             */
/*   Updated: 2023/07/24 12:16:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;
	std::string _darkest_secret;
public :
	int index;
//seters
	void set_first_name(std::string str);
	void set_last_name(std::string str);
	void set_nick_name(std::string str);
	void set_phone_number(std::string str);
	void set_darkset_secret(std::string str);
//geters
	const std::string &get_first_name(void);
	const std::string &get_last_name(void);
	const std::string &get_nick_name(void);
	const std::string &get_phone_number(void);
	const std::string &get_darkest_secret(void);
};
#endif 