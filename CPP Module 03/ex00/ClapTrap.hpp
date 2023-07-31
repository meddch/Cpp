/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:50:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/31 14:03:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	std::string _name;
	int			_Hit_point;
	int			_Energy_point;
	int			_attack_dmg;
	
 public :

	ClapTrap(std::string);
	ClapTrap();
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
};

#endif
