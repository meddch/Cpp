/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:00:59 by mechane           #+#    #+#             */
/*   Updated: 2023/07/26 14:11:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>


class Zombie
{
	std::string _name;
public :
	Zombie();
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif