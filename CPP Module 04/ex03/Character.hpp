/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:24:52 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 11:11:27 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
		std::string const	_name;
		AMateria			*(_inventory[4]);
	public:
		Character(std::string name);
		Character(Character const &other);
		~Character();
		Character & operator=(Character const &other);
		std::string const & getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria	*getMateriaFromInventory(int idx);

};

#endif