/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:19:35 by mechane           #+#    #+#             */
/*   Updated: 2023/07/26 15:48:58 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA(void){return;}

void	HumanA::attack(void)
{
	std::cout <<  _name << " attacks with their " << _weapon.getType() << std::endl;
}
