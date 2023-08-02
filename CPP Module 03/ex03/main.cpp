/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:49:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/02 10:55:34 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
int main()
{
    DiamondTrap    a("heroA");
    DiamondTrap    b("heroB");
    DiamondTrap    c("heroC");


    a.takeDamage(50);
    a.beRepaired(50);
    a.takeDamage(110);
    a.highFivesGuys();
    a.guardGate();
    b.highFivesGuys();
    b.guardGate();
    a.whoAmI();
    b.whoAmI();
}
