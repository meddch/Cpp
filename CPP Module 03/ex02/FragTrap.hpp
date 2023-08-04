/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:13:00 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 08:54:35 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public: 
    FragTrap(std::string name);
    FragTrap();
    ~FragTrap();
    FragTrap& operator=(const FragTrap& other);
    FragTrap(const FragTrap& other);
    void highFivesGuys();
};

#endif