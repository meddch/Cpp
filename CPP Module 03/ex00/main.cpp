/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:49:31 by mechane           #+#    #+#             */
/*   Updated: 2023/07/31 14:02:05 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap myClapTrap("Trex");
    ClapTrap enemyClapTrap("Bot");

    myClapTrap.attack("Enemy");
    enemyClapTrap.attack("Friend");
    myClapTrap.beRepaired(3);
    enemyClapTrap.beRepaired(2);
    myClapTrap.attack("Enemy");
    enemyClapTrap.attack("Friend");
    myClapTrap.takeDamage(5);
    enemyClapTrap.takeDamage(3);
    myClapTrap.beRepaired(2);
    enemyClapTrap.beRepaired(1);
    myClapTrap.attack("Enemy");
    enemyClapTrap.attack("Friend");

    return 0;
}