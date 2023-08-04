/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:10:25 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 13:27:31 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#define MAX_IDEA

class   Brain
{
	std::string _ideas[MAX_IDEA];
	int			_size;
public :
	Brain();
	~Brain();
	Brain& operator=(const Brain& other);
	Brain(const Brain& other);
	std::string* get_Ideas() const;
};

#endif