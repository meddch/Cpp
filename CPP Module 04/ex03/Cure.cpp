/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:24:59 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 10:27:37 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Cure::Cure() : _type("cure")
{
	std::cout << this->_type << " constructed" << std::endl;
}

Cure::~Cure()
{
	std::cout << this->_type << " destroyed" << std::endl;
}

Cure::Cure(Cure const &other) : _type(other.getType())
{
	std::cout << this->_type << " constructed using copy" << std::endl;
}

Cure & Cure::operator=(Cure const &other)
{
	std::cout << "Assigned operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_type = other._type;
	return (*this);
}

std::string const &Cure::getType(void) const
{
	return (this->_type);
}

Cure *Cure::clone() const
{
	Cure	*ret = new Cure;
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::string target_name = target.getName();
	std::cout << " heals " << target_name << "\'s wounds" << std::endl;
}