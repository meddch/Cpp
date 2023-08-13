/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:12:41 by mechane           #+#    #+#             */
/*   Updated: 2023/08/13 10:18:08 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    _name = "Default Diamond";
    ClapTrap::_name = _name + "_clap_name";
    _Energy_point = ScavTrap::_Energy_point;
    _attack_dmg = FragTrap::_attack_dmg;
    _Hit_point = FragTrap::_Hit_point;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(), FragTrap()
{
    _name = name;
    ClapTrap::_name = _name + "_clap_name";
    _Energy_point = ScavTrap::_Energy_point;
    _attack_dmg = FragTrap::_attack_dmg;
    _Hit_point = FragTrap::_Hit_point;
    std::cout << "DiamondTrap Constructor called for " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap : " << _name << " Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_Hit_point = other._Hit_point;
	this->_Energy_point = other._Energy_point;
	this->_attack_dmg = other._attack_dmg;
    ClapTrap::_name = _name + "_clap_name";
	return *this;
}
void		DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI()
{
	std::cout << "My Name is : " << _name;
	std::cout << " and my clapName is : " << ClapTrap::_name << std::endl;
}