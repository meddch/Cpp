/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:23:55 by mechane           #+#    #+#             */
/*   Updated: 2023/08/06 12:28:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): type("None")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default destructor called" << std::endl;
}

AMateria& operator=(const AMateria& other)
{
	if (*this == other)
		return *this;
	this->type = other.type;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

std::string& const AMateria::getType() const
{
	return this->type;
}


