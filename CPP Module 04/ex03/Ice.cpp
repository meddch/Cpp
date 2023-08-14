/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:25:11 by mechane           #+#    #+#             */
/*   Updated: 2023/08/14 15:58:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Ice::Ice() : _type("ice")
{
	std::cout << this->_type << " constructed" << std::endl;;
}

Ice::~Ice()
{
	std::cout << this->_type << " destroyed" << std::endl;
}

Ice::Ice(Ice const &other) : _type(other.getType())
{
	std::cout << this->_type << " constructed using copy constructor" << std::endl;
}

Ice & Ice::operator=(Ice const &other)
{
	std::cout << "Assigned operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_type = other._type;
	return (*this);
}

std::string const &Ice::getType(void) const
{
	return (this->_type);
}

Ice *Ice::clone() const
{
	Ice	*ret = new Ice;
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::string target_name = target.getName();
	std::cout << "* shoots an ice bolt at " << target_name << " *" << std::endl;
}