/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:10:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 07:22:55 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain's Default constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEA ; i++)
		_ideas[i] = "Good idea";
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
	for (int i = 0; i < MAX_IDEA ; i++)
		this->_ideas[i] = other._ideas[i];
    return *this;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain's Copy constructor called" << std::endl;
    *this = other;
}


std::string  Brain::get_Idea(int index) const
{
    if (index < MAX_IDEA && index >= 0)
		return _ideas[index];
	std::cout << "invalid idea index" << std::endl;
	return "";
}

void Brain::set_Idea(int index,const std::string& idea)
{
	if (index < MAX_IDEA && index >= 0)
		_ideas[index] = idea;
}