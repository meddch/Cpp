/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:49:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/01 12:01:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("Bob");
    ScavTrap scavTrap("Alice");

    clapTrap.attack("evil robot");
    scavTrap.attack("evil robot");
    scavTrap.guardGate();

    return 0;
}
