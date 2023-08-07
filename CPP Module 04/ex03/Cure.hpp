/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:25:05 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 06:49:21 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
		std::string _type;
	public:
		Cure();
		~Cure();
		Cure(Cure const & ref);
		Cure & operator=(Cure const & ref);
		std::string const & getType() const;
		Cure *clone() const;
		void use(ICharacter& target);
};

#endif