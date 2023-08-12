/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:50:37 by mechane           #+#    #+#             */
/*   Updated: 2023/08/12 14:28:19 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected :
	std::string _name;
	int			_Hit_point;
	int			_Energy_point;
	int			_attack_dmg;

public :

	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	ClapTrap(const ClapTrap& other);
	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif
