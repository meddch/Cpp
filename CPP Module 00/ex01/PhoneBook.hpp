/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:22:53 by mechane           #+#    #+#             */
/*   Updated: 2023/07/24 17:12:14 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

#define RED  "\033[0;31m"
#define GREEN  "\033[0;32m"
#define BLUE  "\033[0;34m"
#define WH  "\033[0;33m"
#define D  "\033[0;30m"
#define A  "\033[0;35m"

class PhoneBook{
	Contact contacts[8];
	int		_size;
public :
	void		Add(int i);
	void		Search(void);
	void		set_size(int i);
	const int	&get_size(void);
};


#endif