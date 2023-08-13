/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:49:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/13 10:43:52 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("BOB");


    scavTrap.attack("evil robot");
	scavTrap.takeDamage(30);
	scavTrap.beRepaired(15);
    scavTrap.guardGate();

    return 0;
}
