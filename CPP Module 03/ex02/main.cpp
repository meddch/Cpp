/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:49:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/01 13:00:08 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("Bob");
    ScavTrap scavTrap("Alice");
    FragTrap fragTrap("Charlie");

    clapTrap.attack("evil robot");
    scavTrap.attack("evil robot");
    fragTrap.attack("evil robot");
    fragTrap.highFivesGuys();

    return 0;
}
