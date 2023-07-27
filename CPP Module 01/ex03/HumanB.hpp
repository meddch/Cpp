/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:17:22 by mechane           #+#    #+#             */
/*   Updated: 2023/07/27 09:13:35 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #ifndef HUMANB_HPP
 #define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class	 HumanB
{
	Weapon* 	_weapon;
	std::string _name;
public :
	HumanB(std::string name);
	void attack(void);
	void setWeapon(Weapon &weapon);
};

#endif