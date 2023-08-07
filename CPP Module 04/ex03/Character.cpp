/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:28:45 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 11:07:06 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << "A character named \"" << _name << "\" was created" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character named " << this->_name << " was destroyed" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

Character::Character(Character const &other) : _name(other.getName() + "_copy")
{
	for(int i = 0; i < 4; i++)
	{
		if ((other._inventory)[i])
			(this->_inventory)[i] = (other._inventory[i])->clone();
	}
	std::cout << "A character named " << _name << " was created from copy of " << other._name << std::endl;
}

Character & Character::operator=(Character const &other)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
	return (*this);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << this->_name << " tried to equip nothing and it did nothing" << std::endl;
		return ;
	}
	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << this->_name << " can't equip more than 4 Materia";
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << this->_name << " equipped materia " << m->getType() << " in slot " << i << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing" << std::endl;
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " has nothing equipped at slot " << idx << " so he can't unequip it" << std::endl;
	else
	{
		AMateria *ptr = (this->_inventory)[idx];
		std::cout << this->_name << " unequipped " << ptr->getType() << " at slot "<< idx << std::endl;
		(this->_inventory)[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	std::string	name = this->getName();

	if (idx < 0 || idx >= 4 || !(this->_inventory)[idx])
	{
		std::cout << "Nothing found to use at index " << idx << std::endl;
		return ;
	}
	std::cout << name;
	((this->_inventory)[idx])->use(target);
}

AMateria	*Character::getMateriaFromInventory(int idx)
{
	return (this->_inventory)[idx];
}






