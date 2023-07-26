/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:17:22 by mechane           #+#    #+#             */
/*   Updated: 2023/07/26 15:57:24 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #ifndef HUMANB_HPP
 #define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class	 HumanB
{
	Weapon _weapon;
	std::string _name;
public :
	HumanB(std::string name);
	~HumanB();
	HumanB();
	void attack(void);
	void setWeapon(Weapon weapon);
};

 #endif