/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:25:20 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 10:25:52 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
		std::string _type;
	public:
		Ice();
		~Ice();
		Ice(Ice const &other);
		Ice & operator=(Ice const &other);
		std::string const & getType() const;
		Ice *clone() const;
		void use(ICharacter& target);
};

#endif