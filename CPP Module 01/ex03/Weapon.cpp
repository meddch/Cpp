/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:02:10 by mechane           #+#    #+#             */
/*   Updated: 2023/07/27 08:56:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType(void)
{
	return _type;	
}

void Weapon::setType(std::string type)
{ 
	_type = type;
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(){};

