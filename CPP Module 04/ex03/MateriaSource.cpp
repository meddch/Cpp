/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:26:27 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 11:11:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Materia source was created" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
	std::cout << "Materia source was created from copy" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &other)
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

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Materia source was destoryed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Can't learn more than 4 Materia";
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << "Materia " << m->getType() << " learned" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_inventory)[i])
	{
		std::cout << type << " materia does not exit" << std::endl;
		return (NULL);
	}
	std::cout << "Materia " << type << " created" << std::endl;
	return (((this->_inventory)[i])->clone());
}