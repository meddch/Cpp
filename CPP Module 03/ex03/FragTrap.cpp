/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:13:04 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 08:54:05 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _attack_dmg = 30;
    _Hit_point = 100;
    _Energy_point = 100;
    std::cout << "FragTrap Constructor called for " << name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_Hit_point = other._Hit_point;
	this->_Energy_point = other._Energy_point;
	this->_attack_dmg = other._attack_dmg;
	return *this;
}
