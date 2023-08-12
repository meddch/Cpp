/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:51:59 by mechane           #+#    #+#             */
/*   Updated: 2023/08/12 14:58:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default Constructor called" << std::endl;
	_attack_dmg = 20;
    _Hit_point = 100;
    _Energy_point = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _attack_dmg = 20;
    _Hit_point = 100;
    _Energy_point = 50;
    std::cout << "ScavTrap Constructor called for " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap : " << _name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

void ScavTrap::attack(const std::string& target)
{
	if (!_Energy_point || !_Hit_point)
		std::cout << "ScavTrap : " << _name << " can't attack. It has no hit points or energy points left" << std::endl;
	else
	{
		_Energy_point--;
		std::cout << "ScavTrap : " << _name << " attacks " << target << " causing " << _attack_dmg << "  points of damage!" << std::endl;
	}
}
