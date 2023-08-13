/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:49:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/13 10:42:27 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap fragTrap("Charlie");

    fragTrap.attack("evil robot");
	fragTrap.takeDamage(20);
	fragTrap.beRepaired(10);
    fragTrap.highFivesGuys();

    return 0;
}
