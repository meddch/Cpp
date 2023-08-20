/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:12:33 by mechane           #+#    #+#             */
/*   Updated: 2023/08/20 12:03:03 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    std::string  _name;
public :

    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap& operator=(const DiamondTrap& other);
    DiamondTrap(const DiamondTrap& other);
    void    whoAmI();
    void 	attack(const std::string& target);

};

#endif