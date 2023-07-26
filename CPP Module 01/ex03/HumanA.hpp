/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:10:52 by mechane           #+#    #+#             */
/*   Updated: 2023/07/26 15:44:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef HUMANA_HPP
 #define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class	 HumanA
{
	Weapon _weapon;
	std::string _name;
public :
	~HumanA();
	HumanA(std::string name, Weapon weapon);
	HumanA();
	void attack(void);
};

 #endif