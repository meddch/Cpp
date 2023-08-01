/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:52:45 by mechane           #+#    #+#             */
/*   Updated: 2023/08/01 12:14:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
public: 
    ScavTrap(std::string name);
    ScavTrap();
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& other);
    void guardGate();
};

#endif