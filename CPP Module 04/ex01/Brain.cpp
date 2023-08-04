/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:10:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 13:37:05 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() :
{
    std::cout << "Brain's Default constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEA ; i++)
		_ideas[i] = "Good idea\n";
	_size = 0;
}

Brain::~Brain()
{
    std::cout << "Brain's destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain's Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_size = other._size;
	for (int i = 0; i < MAX_IDEA ; i++)
		this->_ideas[i] = other._ideas[i];
    return *this;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain's Copy constructor called" << std::endl;
    *this = other;
}


std::string*  Brain::get_Ideas() const
{
    return _ideas;
}