/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:25:43 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 11:10:27 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
		AMateria	*(_inventory[4]);
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		~MateriaSource();
		MateriaSource & operator=(MateriaSource const &other);
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};

#endif