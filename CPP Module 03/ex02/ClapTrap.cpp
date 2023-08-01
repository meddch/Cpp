/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:51:00 by mechane           #+#    #+#             */
/*   Updated: 2023/08/01 12:03:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " got destroyed" << std::endl;
}
ClapTrap::ClapTrap() : _name("Default"), _Hit_point(10), _Energy_point(10), _attack_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_Hit_point = 10;
	_Energy_point = 10;
	_attack_dmg = 0;
	std::cout << "Constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void	ClapTrap::attack(const std::string& target)
{
	if (!_Energy_point || !_Hit_point)
		std::cout << "ClapTrap " << _name << "can't attack. It has no hit points or energy points left" << std::endl;
	else
	{
		_Energy_point--;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack_dmg << "  points of damage!" << std::endl ;
	} 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_Hit_point)
		std::cout << "ClapTrap " << _name << "can't take any more damage. It has no HP(hit points) left !" << std::endl;
	else
	{
		_Hit_point -= amount;
		if (_Hit_point > 0)
        	std::cout << "ClapTrap takes " << amount << " damage and has " << _Hit_point << " hit points left !" << std::endl;
		else
		{
        	_Hit_point = 0;
        	std::cout << "ClapTrap takes " << amount << " damage and has been defeated " << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Hit_point == 10)
        std::cout << "ClapTrap can't be repaired any further. Its hit points are already at the maximum value." << std::endl ;
	else
	{
		if (_Energy_point == 0)
    	    std::cout << "ClapTrap can't be repaired. It has no energy points left " << std::endl;
		else
		{
    		_Energy_point--;
			_Hit_point += amount;
			if (_Hit_point > 10) 
    	    	_Hit_point = 10;
    		std::cout << "ClapTrap is repaired by " << amount << " hit points and has " << _Hit_point << " hit points remaining." << std::endl;
		}
	}
}