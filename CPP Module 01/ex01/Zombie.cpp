/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:45:17 by mechane           #+#    #+#             */
/*   Updated: 2023/07/27 07:43:03 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::~Zombie(void)
{
	std::cout << _name << "    GRRaaaaaaR" << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* Zombies = new Zombie[N];
	
	for(int i = 0; i < N ;i++)
		Zombies[i].setName(name);
	return Zombies;
}

void Zombie::setName(std::string name)
{
	_name = name;
}